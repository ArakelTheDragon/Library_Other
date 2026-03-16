#include <Arduino.h>

#define NUM_LEDS 9

const int ledPins[NUM_LEDS] = {D0, D1, D2, D3, D4, D5, D6, D7, D8}; // Pinout for your LEDs
const int statusLedPin = A0; // The LED connected to A0 for status (always ON)

const unsigned long delayBetween = 200; // 200 milliseconds between switching pins
const unsigned long holdTime = 2;    // 1800 milliseconds = 1.8 seconds (time for all LEDs to stay ON)

void setup() {
  Serial.begin(9600);
  delay(1000);

  // Set the status LED (A0) to OUTPUT and turn it ON
  pinMode(statusLedPin, OUTPUT);
  digitalWrite(statusLedPin, HIGH); // The status LED is always ON

  // Set all other pins to OUTPUT mode
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH); // Start with all LEDs off
  }
}

void loop() {
  // Turn LEDs ON one by one (pins LOW)
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], LOW);  // Turn LED ON
    delay(delayBetween);             // Wait before turning on the next LED
  }

  delay(holdTime); // Keep all LEDs ON for 1.8 seconds

  // Turn LEDs OFF one by one (pins HIGH) in reverse order
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);  // Turn LED OFF
    delay(delayBetween);             // Wait before turning off the next LED
  }

  delay(holdTime); // Keep all LEDs OFF for 1.8 seconds before repeating
}
