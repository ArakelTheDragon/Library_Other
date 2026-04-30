# MOSFET Driver (40 Hz Square Wave Simulation)

This tutorial demonstrates how a **MOSFET** behaves as a digital switch when driven by a  
**40 Hz square‑wave input**.  
The circuit uses a 12 V supply, a gate resistor, a load resistor, and an N‑channel MOSFET configured as a low‑side switch.

---

## 🔧 Circuit Components
- **DC Supply:** 12 V  
- **MOSFET:** N‑channel (logic‑level recommended)  
- **Drain Load Resistor:** 1 kΩ  
- **Gate Resistor:** 1 kΩ  
- **Signal Source:** 40 Hz square wave  
- **Configuration:** Low‑side MOSFET driver  

---

## ⚙️ How It Works
1. The 40 Hz square wave drives the **MOSFET gate** through a 1 kΩ resistor.  
2. When the input goes **HIGH**, the MOSFET gate charges, turning the MOSFET **ON**.  
3. Current flows from drain → source, pulling the output low and powering the load.  
4. When the input goes **LOW**, the gate discharges and the MOSFET switches **OFF**.  
5. The oscilloscope shows a clean **square‑wave switching** waveform at the drain.

This demonstrates how MOSFETs are used in **PWM control, motor drivers, LED drivers, and digital switching**.

---

## 📊 Simulation Output
- **Max Voltage:** ~11.8 V  
- **Min Voltage:** ~120 µV  
- **RMS Voltage:** ~8.3 V  
- **Frequency:** 40 Hz  
- **Time Scale:** 2 ms/div  
- **Waveform:** Square wave at the MOSFET drain  

---

## 📁 Project Files  
👉 **[MOSFET Driver Folder](ca://s?q=Open_MOSFET_Driver_GitHub_folder)**  
(Add your GitHub link once the folder is created.)

---

## 💡 Practical Tips
- Lowering the gate resistor increases switching speed.  
- Using a logic‑level MOSFET ensures full enhancement at low gate voltages.  
- Try increasing the frequency to see when the MOSFET begins to heat or distort the waveform.

---

## 🔗 CfCbazar Electronics Tutorials
Explore more circuit guides and beginner‑friendly projects:  
🛒 https://www.ebay.com/usr/cfcbazar
