#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "CfC WiFi"; // Replace with your WiFi name
const char* password = "CfC Password"; // Replace with your WiFI password

// Create a web server object that listens on port 80
ESP8266WebServer server(80);

// Variables to store the button states
bool buttonState[5] = {false, false, false, false, false};

// Pin assignments for buttons and sensors
const int buttonPins[5] = {LED_BUILTIN, D2, D3, D4, D5};  // First button controls the built-in LED
const int sensorPins[5] = {D6, D7, D8, D0, D9};  // Example pins for sensors

void setup() {
  Serial.begin(115200);

  // Set up buttons as output pins
  for (int i = 0; i < 5; i++) {
    pinMode(buttonPins[i], OUTPUT);
  }

  // Set up sensors as input pins
  for (int i = 0; i < 5; i++) {
    pinMode(sensorPins[i], INPUT);
  }

  // Wi-Fi connection
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  // Timeout for Wi-Fi connection
  int wifiCounter = 0;
  while (WiFi.status() != WL_CONNECTED && wifiCounter < 20) {  // Timeout after 20 attempts
    delay(1000);
    Serial.print(".");
    wifiCounter++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi");
  } else {
    Serial.println("\nFailed to connect to WiFi, continuing without WiFi");
  }

  Serial.println(WiFi.localIP());

  // Define web server routes
  server.on("/", handleRoot);  // Home page
  for (int i = 0; i < 5; i++) {
    String route = "/toggleButton" + String(i);
    server.on(route.c_str(), [i]() { toggleButton(i); });
  }

  // Start the web server
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();  // Handle web server requests
}

// Function to toggle button state
void toggleButton(int index) {
  buttonState[index] = !buttonState[index];
  digitalWrite(buttonPins[index], buttonState[index] ? LOW : HIGH);  // Control the LED
  server.send(200, "text/html", generateHTML());
}

// Home page handler
void handleRoot() {
  server.send(200, "text/html", generateHTML());
}

// Function to generate HTML for the web page
String generateHTML() {
  String html = "<html><body><h1>ESP8266 Web Control</h1>";

  // Display buttons with ON/OFF status
  for (int i = 0; i < 5; i++) {
    html += "<p>Button " + String(i + 1) + ": ";
    html += "<a href=\"/toggleButton" + String(i) + "\">";
    html += buttonState[i] ? "ON" : "OFF";
    html += "</a></p>";
  }

  // Display sensor data
  html += "<h2>Sensor Data</h2>";
  for (int i = 0; i < 5; i++) {
    int sensorValue = digitalRead(sensorPins[i]);  // Read sensor value (0 or 1)
    html += "<p>Sensor " + String(i + 1) + ": " + String(sensorValue) + "</p>";
  }

  html += "</body></html>";
  return html;
}
