import time
import requests
import pygame

# Initialize the pygame mixer
pygame.mixer.init()

# Path to your sound file
SOUND_FILE = "soundfile.mp3"  # Change this to your sound file

def is_connected():
    try:
        # Attempt to reach a reliable site
        response = requests.get('https://www.google.com', timeout=5)
        return True
    except requests.ConnectionError:
        return False

def play_sound():
    try:
        # Load and play the sound file
        pygame.mixer.music.load(SOUND_FILE)
        pygame.mixer.music.play()
        
        # Wait until the sound finishes playing
        while pygame.mixer.music.get_busy():
            time.sleep(0.1)
    except Exception as e:
        print(f"Error playing sound: {e}")

def monitor_connection(check_interval=5):
    while True:
        if not is_connected():
            print("Internet connection dropped. Playing sound...")
            play_sound()
        else:
            print("Internet connection is up.")
        
        time.sleep(check_interval)

if __name__ == "__main__":
    monitor_connection()
