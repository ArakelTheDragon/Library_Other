import speedtest
import time
import os

LOG_FILE = 'log.txt'
INTERVAL = 30 * 60  # 30 minutes in seconds
MAX_RUNS = 65534  # Maximum number of runs to prevent overflow

def measure_speed():
    st = speedtest.Speedtest()
    st.get_best_server()

    # Measure download speed
    download_speed = st.download() / 1e6  # Convert to Mbps
    # Measure upload speed
    upload_speed = st.upload() / 1e6  # Convert to Mbps
    # Measure ping
    ping = st.results.ping

    return download_speed, upload_speed, ping

def log_average(avg_download, avg_upload, avg_ping, runs):
    with open(LOG_FILE, 'w') as file:  # Write mode to overwrite with only the average
        file.write(f"Average Results after {runs} runs:\n")
        file.write(f"Download: {avg_download:.2f} Mbps, Upload: {avg_upload:.2f} Mbps, Ping: {avg_ping:.2f} ms\n")

def main():
    run_number = 0
    cumulative_download = 0.0
    cumulative_upload = 0.0
    cumulative_ping = 0.0

    print("Starting continuous speed test... Press Ctrl+C to stop.")

    try:
        while run_number < MAX_RUNS:
            run_number += 1
            print(f"Running speed test {run_number} of {MAX_RUNS}...")

            try:
                download_speed, upload_speed, ping = measure_speed()
                
                # Update cumulative values
                cumulative_download += download_speed
                cumulative_upload += upload_speed
                cumulative_ping += ping

                # Calculate averages
                avg_download = cumulative_download / run_number
                avg_upload = cumulative_upload / run_number
                avg_ping = cumulative_ping / run_number

                log_average(avg_download, avg_upload, avg_ping, run_number)

                print(f"Run {run_number}: Download: {download_speed:.2f} Mbps, Upload: {upload_speed:.2f} Mbps, Ping: {ping:.2f} ms")
                print(f"Averages: Download: {avg_download:.2f} Mbps, Upload: {avg_upload:.2f} Mbps, Ping: {avg_ping:.2f} ms\n")

            except Exception as e:
                print(f"An error occurred: {e}")

            print(f"Waiting for {INTERVAL / 60} minutes before the next test...\n")
            time.sleep(INTERVAL)

    except KeyboardInterrupt:
        print("\nSpeed test stopped manually.")
        print(f"Final Averages after {run_number} runs: Download: {avg_download:.2f} Mbps, Upload: {avg_upload:.2f} Mbps, Ping: {avg_ping:.2f} ms")

if __name__ == "__main__":
    main()
