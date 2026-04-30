# LRC Oscillator Circuit (Simulation)

This tutorial demonstrates how an **LRC oscillator** works using a simple inductor–resistor–capacitor loop powered by a DC source. When the switch is toggled, the stored energy oscillates between the inductor and capacitor, producing a decaying AC waveform.

## 🔧 Circuit Components
- **Inductor:** 1 H  
- **Capacitor:** 15 μF  
- **Resistors:** 10 Ω (series), 100 Ω (load/damping)  
- **DC Source:** 5 V  
- **Switch:** Momentary toggle to start oscillation  

## ⚙️ How It Works
1. The DC source charges the capacitor when the switch is ON.  
2. Turning the switch OFF disconnects the supply, allowing the LC tank to oscillate freely.  
3. Energy transfers back and forth between the inductor and capacitor.  
4. The resistors introduce damping, causing the oscillation amplitude to decay over time.  
5. The simulation graph shows the resulting AC waveform.

## 📊 Simulation Output
- **Max Voltage:** ~11.7 V  
- **Min Voltage:** ~–12.5 V  
- **RMS Voltage:** ~5.1 V  
- **Time Scale:** 2 ms/div  
- **Waveform:** Decaying sinusoidal oscillation  

This is a classic example of a **damped harmonic oscillator** in electronics.

---

## 📁 Project Files  
Full project folder, images, and source files:  
👉 **https://github.com/ArakelTheDragon/Library_Other/tree/main/LRC_Oscillator**  
*(Update the folder name once you add the LRC project.)*

---

### 💡 Practical Tip
LRC oscillators are the foundation of radio circuits, filters, resonators, and timing systems.  
Try adjusting the capacitor or inductor values to see how the frequency changes.

---

### 🔗 CfCbazar Electronics Tutorials
Explore more circuit guides and beginner‑friendly projects:  
🛒 https://www.ebay.com/usr/cfcbazar
