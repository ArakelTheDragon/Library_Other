imagesmages� LED Blinker (AC 50 Hz) — Bridge‑LED Alternating Circuit

A simple AC‑driven LED blinker that uses a bridge‑style diode arrangement to alternate LED conduction on each half‑cycle of a 50 Hz AC waveform.

---

🔧 Components Used
- AC Voltage Source (50 Hz)  
- 4× Diodes (D1–D4)  
- 1× LED Load (two LEDs alternating)  
- 500 Ω Resistor (R1)

---

⚙️ How the Circuit Works
This circuit uses a 50 Hz AC source feeding a diode arrangement that behaves like a simplified bridge.  
During the positive half‑cycle, current flows through one LED path, lighting D1/D2.  
During the negative half‑cycle, current reverses and lights D3/D4.  
The result is an alternating LED blink at 50 Hz, too fast for the eye to see as blinking, but clearly visible in simulation waveforms.  
This demonstrates AC rectification, diode directionality, and LED conduction behavior.

---

📊 Simulation Details
- Input Frequency: 50 Hz  
- Peak Voltage: ~±11.3 V  
- RMS Voltage: ~7.3 V  
- Waveform: AC sine  
- Time Scale: 2 ms/div  

---

🖼️ Circuit & Waveform Image
This project uses a single combined image showing both the circuit and the oscilloscope output.

/Images/circuit.jpg

---

💡 Practical Notes
- LEDs will not visibly blink at 50 Hz — simulation reveals the alternation.  
- Increasing frequency reduces LED conduction time per cycle.  
- Using different LED colors can show conduction differences due to forward voltage.  

---

📁 Project Files
👉 (Insert your GitHub folder link here)

---

🔗 Related CfCbazar Tutorials
- MOSFET Driver  
- BJT Switch  
- Bridge Rectifier

---

🛒 CfCbazar Store
Explore more guides, kits, and digital tools:  
https://www.ebay.com/usr/cfcbazar

---
