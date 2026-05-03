# ⚡ Power Transmission Line Demo (40 Hz Simulation)

This project demonstrates how **AC power transmission** works by comparing two circuits:

1. A **realistic transmission line** with inductors (representing long-distance power lines)
2. A **purely resistive line** with no inductance

The goal is to show how **inductance affects current, voltage, phase shift, and power efficiency** in AC systems.

---

## 🔍 Overview

Real power lines behave like **long inductors**.  
Inductance adds **reactive impedance**, which:

- Limits current  
- Reduces I²R losses  
- Stabilizes AC waveforms  
- Introduces phase shift  
- Improves transmission efficiency  

This simulation models these effects at **40 Hz**.

---

## 🧩 Circuit 1 — With Inductors (Realistic Line)

**Components:**
- 40 Hz AC source  
- 10 Ω source resistor  
- 1 H line inductor  
- 500 Ω load resistor  
- 1 mH secondary inductor  
- 200 Ω final load resistor  

**Measured Values:**
- **Voltage:** ~113.5 V peak  
- **RMS Voltage:** ~79.2 V  
- **Current:** **400.34 mA RMS**  
- **Waveform:** Sinusoidal with visible phase shift  

**Explanation:**  
The 1 H inductor creates significant reactance:

\[
X_L = 2\pi f L = 2\pi \cdot 40 \cdot 1 = 251.3\ \Omega
\]

This increases total impedance and reduces current flow, just like real transmission lines.

---

## 🧩 Circuit 2 — Without Inductors (Resistive Only)

**Components:**
- 40 Hz AC source  
- 10 Ω resistor  
- 500 Ω resistor  
- 500 Ω resistor  
- 200 Ω resistor  

**Measured Values:**
- **Current:** **70.13 mA RMS**  
- **Waveform:** Pure sinusoid, no phase shift  

**Explanation:**  
Without inductors, the circuit is purely resistive.  
No reactive behavior is present, and current is determined only by total resistance.

---

## ⚡ Key Concepts Demonstrated

- **Inductive Reactance**  
- **AC Impedance**  
- **Phase Shift (Voltage leads Current)**  
- **Reactive Power**  
- **Transmission Line Behavior**  
- **Power Loss Reduction (I²R)**  

This simulation is a simplified model of how real power grids move electricity efficiently over long distances.

---

## 📈 Waveform Summary

- Peak Voltage: **113.2 V**  
- Minimum Voltage: **–113.3 V**  
- RMS Voltage: **79.2 V**  
- Frequency: **40 Hz**  
- Time Scale: **2 ms/div**  

---

## 📁 Files Included

- Circuit diagrams  
- Simulation screenshots  
- Waveform captures  
- Component values  
- Analysis notes  

---

## 🛒 CfCbazar Resources

Explore more electronics guides, kits, and tutorials:  
https://www.ebay.com/usr/cfcbazar
