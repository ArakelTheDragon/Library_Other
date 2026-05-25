// Built in libs
#include <SHA3.h> // Crypto library

// Prototypes
void printHex(const byte *data, size_t len);
void hashMessage(const char *message);

// Global def, vars that won't change
#define dBAUD 9600

// Global vars, vars that change

void setup() {
  Serial.begin(dBAUD);
  while (!Serial) {
    ; // Wait for serial module to be initialized
  }
  Serial.print("\nSerial initialized.\n");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // LED OFF initially
}

void loop() {
  hashMessage("Test WTK network!");         // Call hashing function
  digitalWrite(LED_BUILTIN, LOW);  // Blink LED ON
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH); // Blink LED OFF
  delay(1000);                     // Wait before next hash
}

// Function definitions after main()

void hashMessage(const char *message) {
  //const char *message = "Test WTK network!"; // Moved to funct
  byte hash[32]; // SHA3-256 output

  SHA3_256 sha3;
  sha3.reset();
  sha3.update((const byte *)message, strlen(message));
  sha3.finalize(hash, sizeof(hash));

  Serial.println(message);
  Serial.print("SHA3-256: ");
  printHex(hash, sizeof(hash));
}

void printHex(const byte *data, size_t len) {
  for (size_t i = 0; i < len; i++) {
    if (data[i] < 16) Serial.print("0");
    Serial.print(data[i], HEX);
  }
  Serial.println();
}
