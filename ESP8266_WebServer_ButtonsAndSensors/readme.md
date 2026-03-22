# **ESP8266 Web-Controlled I/O Dashboard**

This project turns an ESP8266 into a simple yet powerful **web‑controlled dashboard** for managing digital outputs and monitoring sensor inputs over Wi‑Fi.  
It hosts a lightweight HTTP server that provides a clean HTML interface where users can toggle five outputs (including the built‑in LED) and view the real‑time state of five digital sensors.

---

## 🚀 **Features**

- **Wi‑Fi‑enabled control panel** accessible from any browser on the same network  
- **5 controllable outputs**, including the ESP8266 built‑in LED  
- **5 digital sensor inputs** displayed live on the webpage  
- **Auto‑generated HTML interface** with ON/OFF toggle links  
- **Simple routing system** using `ESP8266WebServer`  
- **Failsafe Wi‑Fi timeout** to prevent lockups  
- **Clean, readable, and extendable code structure**

---

## 🧩 **How It Works**

Once powered on, the ESP8266:

1. Connects to your Wi‑Fi network  
2. Starts a web server on port 80  
3. Serves a dynamic HTML page showing:
   - Button states (ON/OFF)
   - Sensor readings (0/1)
4. Responds to `/toggleButtonX` routes to flip output states  
5. Updates the page instantly after each action  

The interface is intentionally minimal so it loads fast and works on any device.

---

## 📡 **Web Interface Preview**

- **Button Controls:**  
  Each button displays its current state and toggles with a single click.

- **Sensor Readout:**  
  Shows the digital value (`HIGH`/`LOW`) of each connected sensor pin.

---

## 🔧 **Hardware Setup**

| Function | Pins Used |
|---------|-----------|
| Output Buttons | `LED_BUILTIN`, `D2`, `D3`, `D4`, `D5` |
| Sensor Inputs | `D6`, `D7`, `D8`, `D0`, `D9` |

You can easily remap these pins to match your own hardware.

---

## 🛠️ **Technologies Used**

- **ESP8266WiFi.h** — Wi‑Fi connectivity  
- **ESP8266WebServer.h** — Lightweight HTTP server  
- **Arduino IDE / PlatformIO** — Development environment  

---

## 🌐 **Accessing the Web Server**

After connecting to Wi‑Fi, the ESP8266 prints its assigned IP address to the Serial Monitor:

```
Web server IP: xxx.xxx.xxx.xxx
```

Open that address in your browser to access the dashboard.

---

## 📦 **Use Cases**

- Home automation  
- Remote relay control  
- Sensor monitoring  
- IoT prototyping  
- ESP8266 learning projects  
