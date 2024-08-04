// The IP address is not displayed in the terminal, but it will be on your rotuers page, its something like 192.168.0.92
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <WiFiClient.h>

const char* ssid = "WifiSSID"; // Wifi name
const char* password = "PW"; // WiFi password

AsyncWebServer server(80);

// Parameters for speed test
const int speedTestDuration = 10; // duration in seconds for speed test
const int checkInterval = 24 * 60 * 60 * 1000; // Interval for daily checks in milliseconds

// Variables for tracking
unsigned long lastCheck = 0;
unsigned long lastSpeedTest = 0;
int disconnectCount = 0;
float dailyTotalSpeed = 0;
int speedTestCount = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi");

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body><h1>Internet Speed Info</h1>";
    html += "<p>Average Speed Today: " + String(dailyTotalSpeed / max(1, speedTestCount)) + " Mbps</p>";
    html += "<p>Disconnect Count: " + String(disconnectCount) + "</p>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  server.begin();
}

void loop() {
  if (millis() - lastCheck >= checkInterval) {
    // Reset daily counters
    dailyTotalSpeed = 0;
    speedTestCount = 0;
    disconnectCount = 0;
    lastCheck = millis();
  }

  if (millis() - lastSpeedTest >= speedTestDuration * 1000) {
    performSpeedTest();
    lastSpeedTest = millis();
  }

  if (WiFi.status() != WL_CONNECTED) {
    disconnectCount++;
    WiFi.reconnect();
  }
}

void performSpeedTest() {
  // Perform a simple speed test
  WiFiClient client;
  if (client.connect("www.google.com", 80)) {
    unsigned long startTime = millis();
    client.print(String("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"));
    unsigned long endTime = millis();

    float downloadSpeed = (client.available() / float(endTime - startTime)) * 1000; // Speed in bytes per second
    dailyTotalSpeed += downloadSpeed / 1e6; // Convert to Mbps
    speedTestCount++;
    
    client.stop();
    Serial.print("Speed Test Result: ");
    Serial.print(downloadSpeed / 1e6); // Convert to Mbps
    Serial.println(" Mbps");
  } else {
    Serial.println("Failed to connect for speed test");
  }
}
