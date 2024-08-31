import requests
import time

# URLs for IP and location checking
IP_CHECK_URL = "https://api.ipify.org?format=json"
GEOLOCATION_API_URL = "http://ip-api.com/json/"

# Expected VPN region and country
EXPECTED_COUNTRY = "Netherlands"  # Change to your VPN's expected country
EXPECTED_REGION = "North Holland"  # Change to your VPN's expected region (if needed)

def get_public_ip():
    """Fetches the current public IP address."""
    try:
        response = requests.get(IP_CHECK_URL)
        response.raise_for_status()
        return response.json().get('ip')
    except requests.RequestException as e:
        print(f"Error fetching public IP: {e}")
        return None

def get_ip_location(ip):
    """Gets the geolocation of the given IP address."""
    try:
        response = requests.get(GEOLOCATION_API_URL + ip)
        response.raise_for_status()
        data = response.json()
        return data.get('country'), data.get('regionName')
    except requests.RequestException as e:
        print(f"Error fetching geolocation: {e}")
        return None, None

def check_vpn_connection():
    """Checks if the VPN connection is working correctly and reliably."""
    ip = get_public_ip()
    if not ip:
        print("Failed to retrieve IP address. Check your internet connection.")
        return

    print(f"Current IP address: {ip}")

    country, region = get_ip_location(ip)
    if not country:
        print("Failed to retrieve IP geolocation.")
        return

    print(f"Detected Location: {country}, {region}")

    if country == EXPECTED_COUNTRY and (EXPECTED_REGION == '' or region == EXPECTED_REGION):
        print("VPN is connected and the location is correct.")
    else:
        print("VPN is either not connected or connected to the wrong region.")

def test_vpn_reliability(test_duration=10, interval=1):
    """
    Tests VPN reliability by making repeated IP checks over a period of time.
    
    :param test_duration: Total duration of the test in seconds.
    :param interval: Time interval between checks in seconds.
    """
    start_time = time.time()
    end_time = start_time + test_duration
    successful_checks = 0
    total_checks = 0

    while time.time() < end_time:
        total_checks += 1
        ip = get_public_ip()
        if ip:
            successful_checks += 1
        else:
            print("Failed to retrieve IP address during reliability test.")

        time.sleep(interval)

    success_rate = (successful_checks / total_checks) * 100
    print(f"VPN Reliability Test: {success_rate:.2f}% success rate over {test_duration} seconds.")

if __name__ == "__main__":
    check_vpn_connection()
    test_vpn_reliability(test_duration=30, interval=5)  # Run reliability test for 30 seconds with 5-second intervals
