📟 AnalogReadSerial – Minimal Analog Input Reader

This project is a lightweight Arduino sketch that continuously reads an analog value from pin A0 and prints changes to the Serial Monitor. It’s ideal for beginners experimenting with potentiometers, analog sensors, or serial data visualization.

✨ Features

- Reads analog input from A0
- Prints the value only when it changes
- Simple, clean structure with a dedicated ADC read function
- Compatible with Serial Monitor and Serial Plotter
- Beginner‑friendly and easy to extend

---

🧰 Hardware Requirements

To run this sketch, you’ll need:

- An Arduino board (Uno, Nano, Mega, etc.)
- A potentiometer (or any analog sensor)
- Jumper wires

Wiring the Potentiometer

| Potentiometer Pin | Connect To |
|-------------------|------------|
| Left pin          | +5V        |
| Center pin        | A0         |
| Right pin         | GND        |

---

📄 Code Overview

The sketch reads the analog value from pin A0 and prints it only when it changes from the previous reading. This reduces serial noise and makes the output easier to interpret.

`cpp
/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

double dSensorValue; // Global variable storing last read value

bool bReadFromADC(); // Function prototype

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  bReadFromADC();
}

bool bReadFromADC() {
  double dTmp = analogRead(A0);

  if (dSensorValue != dTmp) { // Only print when value changes
    dSensorValue = dTmp;
    Serial.println("dSensorValue = ");
    Serial.println(dSensorValue);
    delay(1);
    return 0;
  } else {
    return 1;
  }
}
`

---

🧪 How to Use

1. Connect your potentiometer or analog sensor.
2. Upload the sketch to your Arduino.
3. Open Tools → Serial Monitor or Serial Plotter.
4. Turn the potentiometer and watch the values update only when they change.

---

📈 Example Output

`
dSensorValue =
512
dSensorValue =
513
dSensorValue =
520
`

---

🚀 Future Improvements

Here are some ideas if you want to expand the project:

- Add smoothing or averaging
- Timestamp each reading
- Output JSON for integration with other tools
- Add support for multiple analog channels
- Implement threshold-based triggers
