const imageUrls = [
    { url: "https://cc.free.bg/dat.jpg", size: 1 }, // 1MB
    { url: "https://upload.wikimedia.org/wikipedia/commons/f/fd/Alaus%C3%AD_Inner_yards_east_of_Calle_Sim%C3%B3n_Bol%C3%ADvar_2.jpg", size: 11 }, // 11MB
    { url: "https://upload.wikimedia.org/wikipedia/commons/6/66/Grand-view-point-003.jpg", size: 59 }, // 59MB
    { url: "https://speed.cloudflare.com/__down?bytes=100000000", size: 100 }, // 100MB
    { url: "https://speed.cloudflare.com/__down?bytes=500000000", size: 500 }, // 500MB
    { url: "https://speed.cloudflare.com/__down?bytes=1000000000", size: 1000 }, // 1GB
    { url: "https://upload.wikimedia.org/wikipedia/commons/6/69/%22Houston%2C_Tranquility_base_here_%22_%28LROC563%29.tiff", size: 1200 }, // 1.2GB
    { url: "https://speed.cloudflare.com/__down?bytes=1500000000", size: 1500 } // 1.5GB
];

let testRunning = false;
let lastSpeeds = [];
let speedData = [];
let stableCount = 0;
let chart;

const startBtn = document.getElementById("startTest");
const progressBar = document.getElementById("progress-bar");
const resultsDiv = document.getElementById("results");
const consoleOutput = document.getElementById("console-output");
const speedChartCanvas = document.getElementById("speedChart").getContext("2d");

startBtn.addEventListener("click", startSpeedTest);

async function startSpeedTest() {
    if (testRunning) return;
    testRunning = true;

    startBtn.disabled = true;
    startBtn.textContent = "Running...";
    resultsDiv.innerHTML = "";
    consoleOutput.innerHTML = "";
    progressBar.style.width = "0%";
    lastSpeeds = [];
    speedData = [];
    stableCount = 0;

    initializeGraph();

    let parallelDownloads = 2;
    while (parallelDownloads <= 8) {
        updateProgress(parallelDownloads);
        
        let selectedImages = selectImages(parallelDownloads);
        logToConsole(`Testing ${parallelDownloads} parallel downloads with images: ${selectedImages.map(img => img.size + "MB").join(", ")}`);

        let speeds = await runParallelDownloads(selectedImages, 10); // 10-second timeout
        let totalSpeed = speeds.reduce((acc, s) => acc + s, 0);
        totalSpeed = Math.round(totalSpeed / 5) * 5;

        updateResults();
        lastSpeeds.push(totalSpeed);
        speedData.push({ parallel: parallelDownloads, speed: totalSpeed });

        updateGraph(parallelDownloads, totalSpeed);

        if (lastSpeeds.length >= 3) {
            let [s1, s2, s3] = lastSpeeds.slice(-3);
            if (Math.abs(s1 - s2) < s1 * 0.1 && Math.abs(s2 - s3) < s2 * 0.1) {
                stableCount++;
                if (stableCount >= 2) {
                    logToConsole("Speed stabilized over 3 tests. Finalizing results...");
                    break;
                }
            } else {
                stableCount = 0;
            }
        }

        parallelDownloads++;
    }

    updateProgress(100);
    displayFinalResults();

    testRunning = false;
    startBtn.disabled = false;
    startBtn.textContent = "Start Test";
}

async function runParallelDownloads(selectedImages, timeoutSeconds) {
    let promises = selectedImages.map(img => downloadAndMeasure(img.url, timeoutSeconds));
    return await Promise.all(promises);
}

async function downloadAndMeasure(url, timeoutSeconds) {
    let controller = new AbortController();
    let signal = controller.signal;
    let timeout = setTimeout(() => controller.abort(), timeoutSeconds * 1000);

    let startTime = Date.now();
    let receivedBytes = 0;

    try {
        let response = await fetch(url, { cache: "no-store", signal });
        let reader = response.body.getReader();
        let contentLength = +response.headers.get("content-length") || 0;

        while (true) {
            let { done, value } = await reader.read();
            if (done) break;
            receivedBytes += value.length;

            let elapsed = (Date.now() - startTime) / 1000;
            if (elapsed >= timeoutSeconds) {
                controller.abort();
                break;
            }
        }

        clearTimeout(timeout);
    } catch (err) {
        if (err.name !== "AbortError") {
            console.error("Download error:", err);
        }
    }

    let duration = (Date.now() - startTime) / 1000;
    let sizeMB = receivedBytes / (1024 * 1024);
    let speed = (sizeMB * 8) / duration;

    logToConsole(`Downloaded ${sizeMB.toFixed(2)} MB in ${duration.toFixed(2)} sec → ${Math.round(speed / 5) * 5} Mbps`);
    return speed;
}

function selectImages(parallelDownloads) {
    let speeds = lastSpeeds.slice(-3);
    let avgSpeed = speeds.length ? speeds.reduce((a, b) => a + b, 0) / speeds.length : 0;
    let newImageSizeMB = (avgSpeed * 5) / 8;

    let sortedImages = imageUrls
        .map(img => ({ url: img.url, size: img.size }))
        .sort((a, b) => Math.abs(a.size - newImageSizeMB) - Math.abs(b.size - newImageSizeMB));

    return sortedImages.slice(0, parallelDownloads);
}

function updateResults() {
    let totalSpeed = speedData.reduce((sum, entry) => sum + entry.speed, 0);
    let avgSpeed = speedData.length ? Math.round(totalSpeed / speedData.length) : 0;

    resultsDiv.innerHTML = `<p class="highlight-color">Estimated Speed: <strong>${avgSpeed} Mbps</strong></p>`;
}

function updateProgress(currentGroup) {
    let percent = Math.min(Math.round((currentGroup / 8) * 100), 100);
    progressBar.style.width = `${percent}%`;
}

function displayFinalResults() {
    let totalSpeed = speedData.reduce((sum, entry) => sum + entry.speed, 0);
    let finalSpeed = speedData.length ? Math.round(totalSpeed / speedData.length) : 0;

    resultsDiv.innerHTML += `<p><strong>Test Complete!</strong> Final Speed: ${finalSpeed} Mbps</p>`;
}

function logToConsole(message) {
    consoleOutput.innerHTML += `<p>${message}</p>`;
}

function initializeGraph() {
    if (chart) {
        chart.destroy();
    }

    chart = new Chart(speedChartCanvas, {
        type: "line",
        data: {
            labels: [],
            datasets: [{
                label: "Speed (Mbps)",
                data: [],
                borderColor: "blue",
                borderWidth: 2,
                fill: false
            }]
        },
        options: {
            scales: {
                x: { title: { display: true, text: "Parallel Downloads" } },
                y: { title: { display: true, text: "Speed (Mbps)" } }
            }
        }
    });
}

function updateGraph(parallel, speed) {
    chart.data.labels.push(parallel);
    chart.data.datasets[0].data.push(speed);
    chart.update();
}