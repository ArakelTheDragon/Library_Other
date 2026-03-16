#include <U8g2lib.h>
#include <Wire.h>

U8G2_ST7567_ENH_DG128064I_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE); // GLCD initialization

// Pin definitions
const int sensorPin = A0; // Flying Fish sensor connected to A0

bool isLocked = true;
unsigned long unlockTime = 0;
unsigned long lockDelay = 5000;
int scanCount = 0;

void setup() {
  Serial.begin(115200);

  // Initialize the GLCD
  u8g2.setI2CAddress(0x3F * 2); // Set the I2C address (adjust as necessary)
  u8g2.begin();
  u8g2.clearBuffer();
  displayStatus();
}

void loop() {
  // Read the sensor value from A0
  int sensorValue = analogRead(sensorPin);
  
  // Display the sensor value on the GLCD
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr); // Set the font
  u8g2.drawStr(0, 10, "Flying Fish Sensor");

  u8g2.setCursor(0, 30);
  u8g2.print("Value: ");
  u8g2.print(sensorValue); // Show the sensor reading

  u8g2.sendBuffer(); // Transfer to display

  delay(500); // Update the display every 500 milliseconds
}

void displayStatus() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr); // Set the font
  u8g2.drawStr(0, 10, isLocked ? "Locked" : "Unlocked");
  
  u8g2.setCursor(0, 30);
  u8g2.print("Scans: ");
  u8g2.print(scanCount);
  
  u8g2.sendBuffer(); // Transfer to display
}
