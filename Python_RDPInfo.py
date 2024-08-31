import socket
import requests
import os

def get_pc_info():
    # Get the PC (host) name
    pc_name = socket.gethostname()
    
    # Get the local IP address
    local_ip = socket.gethostbyname(pc_name)

    # Get the public IP address
    try:
        public_ip = requests.get('https://api.ipify.org').text
    except requests.RequestException:
        public_ip = "Unable to fetch public IP"
    
    # Get the current user account
    user_account = os.getlogin()

    return {
        "PC Name": pc_name,
        "Local IP Address": local_ip,
        "Public IP Address": public_ip,
        "User Account": user_account
    }

if __name__ == "__main__":
    info = get_pc_info()
    print("PC Name:", info["PC Name"])
    print("Local IP Address:", info["Local IP Address"])
    print("Public IP Address:", info["Public IP Address"])
    print("User Account:", info["User Account"])
