⚡ CfCbazar Parallel Stream Speed Test
A fast, browser‑based internet speed test that measures download performance using parallel HTTP streams, real‑time graphing, and detailed console output. No installation, no backend—fully client‑side.

---

🚀 Overview

This project is a standalone HTML/JS application that benchmarks your internet download speed by fetching multiple large files in parallel. It simulates real‑world usage more accurately than single‑stream tests by scaling from 2 to 8 parallel connections.

The tool provides:

- Real‑time speed measurements  
- A dynamic Chart.js graph  
- Console‑style logs of each download stream  
- Automatic outlier removal  
- Final summary with max and average speeds  
- SEO‑optimized metadata and social preview tags  

---

🧩 How It Works

The test runs in groups of parallel downloads:

1. For each group size (2 → 8), the app selects files of increasing size.  
2. Each file is fetched with a 2‑second timeout to simulate burst throughput.  
3. The script measures:
   - Bytes received  
   - Duration  
   - Calculated Mbps  
4. Results are logged and plotted live.  
5. After all groups finish:
   - The lowest result is dropped  
   - The maximum and average speeds are displayed  

---

📊 Features

✔ Parallel Stream Testing
Simulates real‑world multi‑connection downloads.

✔ Real‑Time Graph
Uses Chart.js to visualize speed scaling across parallel groups.

✔ Console Output
Shows detailed per‑stream logs, including MB downloaded and Mbps.

✔ Progress Bar
Indicates test progress from start to finish.

✔ SEO‑Ready
Includes Open Graph, Twitter Card, and structured JSON‑LD metadata.

✔ Fully Client‑Side
No backend server required—runs entirely in the browser.

---

🛠 Technologies Used

| Component | Purpose |
|----------|---------|
| HTML5 | UI structure and metadata |
| CSS3 | Styling and layout |
| JavaScript (ES6) | Core logic, parallel downloads, calculations |
| Chart.js | Real‑time graph rendering |
| Fetch API + Streams | Download measurement |
| AbortController | Timeout handling |

---

📂 Project Structure

`
/project-root
│
├── index.html        # Main application
├── assets/           # (Optional) Images, icons, previews
└── README.md         # Documentation
`

---

▶ Running the Project

No build steps. No dependencies.

Just open:

`
index.html
`

…in any modern browser.

---

🌐 Test File Sources

The tool downloads files from:

- Wikimedia Commons (large images)
- Cloudflare Speed Test endpoints (down?bytes=...)
- Local small test file (dat.jpg)

These provide a mix of sizes from 1 MB → 1.5 GB.

---

📈 Example Output

`
→ Testing 4 parallel streams…
  • 1MB, 11MB, 59MB, 100MB
    • 8.12 MB in 2.00 s → 32.5 Mbps
    • 9.01 MB in 2.00 s → 36.0 Mbps
    • 7.55 MB in 2.00 s → 30.2 Mbps
    • 8.44 MB in 2.00 s → 33.8 Mbps
  → Group 4 speed: 132.5 Mbps
`

---

📜 License

This project is part of the CfCbazar Beta Test suite.  
You may modify and use it freely, but attribution is appreciated.

---

🔗 Related Tools

- CfCbazar Tools Hub: cc.free.bg/diy & cfcbazar.42web.io/diy

.
