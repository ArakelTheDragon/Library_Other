# 📘 Low‑Pass RC Filter — Electronics Tutorial  
A simple resistor–capacitor network that removes high‑frequency noise from your signal.

---

## 🔧 Project Overview  
This project demonstrates how an **RC low‑pass filter** smooths a noisy input signal.  
A resistor and capacitor work together to block high‑frequency components while allowing low‑frequency signals to pass.

This is one of the most widely used filters in electronics — audio, sensors, microcontroller inputs, and power conditioning.

---

## 🧩 Circuit Components  
- **AC Source (85 Hz)** — main signal  
- **Noise Injection Branch** — adds high‑frequency interference  
- **1 kΩ Resistor** — limits noise current  
- **187 Ω Resistor** — forms the RC time constant with the capacitor  
- **10 µF Capacitor** — shunts high‑frequency noise to ground  
- **Output Node** — filtered signal

---

## 🧠 How the RC Filter Works  
Capacitor reactance decreases with frequency:

`X_C = 1 / (2 · π · f · C)`

- **Low frequencies** → large `X_C` → capacitor blocks → signal passes  
- **High frequencies** → small `X_C` → capacitor conducts → noise goes to ground  

Result: **High‑frequency noise is removed**, leaving a smooth waveform.

---

## 📉 Simulation Behavior  
- Output waveform becomes smoother  
- High‑frequency spikes disappear  
- Low‑frequency signal remains mostly unchanged  
- RMS ≈ 2.5 V  
- Max ≈ +3.5 V / Min ≈ –3.5 V  

---

## 🧮 Low‑Pass Filter Cutoff Frequency  
Use the DigiKey calculator:  
https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-low-pass-and-high-pass-filter

### 🔢 Enter your values  
- **R = 187 Ω**  
- **C = 10 µF**

**Cutoff frequency formula:**

`f_c = 1 / (2 · π · R · C)`

**Calculation with your values:**

`f_c = 1 / (2 · π · 187 · 0.00001)`  
`f_c ≈ 85.0 Hz`

### 🎯 Interpretation  
Your cutoff frequency is **≈ 85 Hz**, exactly matching your signal frequency.

This means:  
- Frequencies **below 85 Hz** pass through  
- Frequencies **above 85 Hz** are attenuated  
- High‑frequency noise is removed effectively  
- The 85 Hz signal is preserved but slightly smoothed  

---

## 🗂️ Recommended GitHub Folder Structure  
```
/LowPassFilter_RC/
│── README.md
└── /Images/
    └── circuit.jpg
```

---

## 🖼️ Image Embed (for README)  
![Low Pass RC Filter](https://raw.githubusercontent.com/ArakelTheDragon/Library_Other/main/LowPassFilter_RC/Images/circuit.jpg)

---

## 🎥 Optional: YouTube Short Script  
**Title:** RC Low‑Pass Filter Explained Fast  

**Script:**  
- Show noisy signal  
- Show RC filter  
- Show clean output  
- Text overlay: “Capacitors block high frequencies. Noise removed.”  
- End with CfCbazar branding

---

## ✔️ End of README
