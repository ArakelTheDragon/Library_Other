# 📘 Low‑Pass RL Filter — Electronics Tutorial  
Clean up noisy signals using a simple inductor‑based low‑pass filter.

---

## 🔧 Project Overview  
This project demonstrates how an **RL low‑pass filter** removes high‑frequency noise from a 454 Hz AC signal.  
A noise source is injected into the line, and the RL network filters it out, producing a clean output waveform.

---

## 🧩 Circuit Components  
- **AC Source (454 Hz)** — main signal  
- **Noise Injection Branch** — adds high‑frequency interference  
- **1 kΩ Resistor** — limits noise current  
- **65.5 mH Inductor** — main low‑pass element  
- **187 Ω Shunt Resistor** — dissipates high‑frequency noise  
- **Output Node** — filtered signal

---

## 🧠 How the Filter Works  
Inductor reactance increases with frequency:

`X_L = 2 · π · f · L`

- **Low frequencies** → small `X_L` → signal passes  
- **High frequencies** → large `X_L` → noise blocked  

High‑frequency noise is forced into the **187 Ω resistor to ground**, while the 454 Hz signal passes through the inductor.

Result: **Noise removed, sine wave preserved.**

---

## 📉 Simulation Results  
- Output waveform becomes smooth and sinusoidal  
- Noise amplitude drops significantly  
- RMS ≈ 2.5 V  
- Max ≈ +3.5 V / Min ≈ –3.5 V  

---

## 🧮 Low‑Pass Filter Cutoff Frequency  
Use the DigiKey calculator:  
https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-low-pass-and-high-pass-filter

### 🔢 Enter your values  
- **L = 65.5 mH**  
- **R = 187 Ω**

**Cutoff frequency formula:**

`f_c = R / (2 · π · L)`

**Calculation with your values:**

`f_c = 187 / (2 · π · 0.0655) ≈ 454.7 Hz`

### 🎯 Interpretation  
Your cutoff frequency is **≈ 455 Hz**, almost identical to your signal frequency.

This means:  
- Noise above ~455 Hz is strongly attenuated  
- The 454 Hz signal passes with slight smoothing  
- High‑frequency noise is removed effectively  

---

## 📁 Recommended GitHub Folder Structure  
```
/Low_Pass_Filter/
│── README.md
│── circuit.png
│── simulation.json
└── /images/
    └── low_pass_output.png
```

---

## 🎥 Optional: YouTube Short Script  
**Title:** Low‑Pass Filter Removes Noise — RL Circuit Explained Fast  

**Script:**  
- Show noisy signal  
- Show RL filter  
- Show clean output  
- Text overlay: “Inductors block high frequencies. Noise removed.”  
- End with CfCbazar branding  

---

## ✔️ End of README
