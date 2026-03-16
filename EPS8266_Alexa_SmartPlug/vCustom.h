#ifndef CUSTOM_H
#define CUSTOM_H

#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <fauxmoESP.h>


#include "Settings.h"  // Include the shared header

String SSID = "";
String PASSWORD = "";

fauxmoESP fauxmo;

#define LED_PIN D2
// Pin setup
int pins[] = {D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10}; // Replace with actual usable GPIOs on your D1 C3
const int numPins = sizeof(pins) / sizeof(pins[0]); 

void vSetup() {
    // Pin setup
    for (int p = 0; p < numPins; p++) {
    pinMode(pins[p], OUTPUT);
    digitalWrite(pins[p], LOW);
    }
    // end
    /* Old one pin turn   
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); // LED OFF
    */
    //Serial.begin(115200); Initialized in main.ino
    delay(100);
    Serial.println("[INFO] Starting WiFiManager");

    WiFiManager wifiManager;
    wifiManager.setDebugOutput(true);

    SSID = WiFi.SSID();
    PASSWORD = WiFi.psk();  // May return empty on some boards


    // Uncomment below to force AP mode every time (for testing)
    // wifiManager.resetSettings();

    if (!wifiManager.autoConnect("NodeMCU-Setup", "password123")) {
        Serial.println("[ERROR] Failed to connect and hit timeout");
        ESP.restart();
        delay(5000);
    }

    Serial.println("[INFO] WiFi connected");
    Serial.print("[INFO] IP Address: ");
    Serial.println(WiFi.localIP());

    fauxmo.createServer(true); // For Echo Gen 3+
    fauxmo.setPort(80);
    fauxmo.enable(true);
    fauxmo.addDevice("LED Light");

    fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
        Serial.printf("[FAUXMO] %s switched %s\n", device_name, state ? "ON" : "OFF");
        // digitalWrite(LED_PIN, state ? HIGH : LOW); // Old pin setup turn
        for (int p = 0; p < numPins; p++) {
          digitalWrite(pins[p], state ? HIGH : LOW);
        }
    });
}

void vLoop() {
    fauxmo.handle();
}

#endif
