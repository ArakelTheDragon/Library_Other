#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h>

// Replace with your WiFi credentials
const char* ssid = "TP-Link_CCC7";
const char* password = "69538001";

// Create web server on port 80
ESP8266WebServer server(80);

// Simple function to get MIME type from file extension
String getContentType(String filename) {
  if (filename.endsWith(".html")) return "text/html";
  if (filename.endsWith(".css")) return "text/css";
  if (filename.endsWith(".js")) return "application/javascript";
  if (filename.endsWith(".png")) return "image/png";
  if (filename.endsWith(".jpg") || filename.endsWith(".jpeg")) return "image/jpeg";
  return "text/plain";
}

// Serve any file from LittleFS if it exists
void handleNotFound() {
  String path = server.uri();
  if (path == "/") path = "/index.html";

  if (LittleFS.exists(path)) {
    File file = LittleFS.open(path, "r");
    server.streamFile(file, getContentType(path));
    file.close();
  } else {
    server.send(404, "text/plain", "404: File Not Found");
  }
}

void printSystemInfo() {
  Serial.println("\n=== ESP8266 Resource Info ===");

  // RAM
  Serial.printf("Free heap: %u bytes\n", ESP.getFreeHeap());

  // Flash chip
  Serial.printf("Flash chip size: %u bytes\n", ESP.getFlashChipSize());
  Serial.printf("Sketch size: %u bytes\n", ESP.getSketchSize());
  Serial.printf("Free sketch space: %u bytes\n", ESP.getFreeSketchSpace());

  // LittleFS
  FSInfo fs_info;
  if (LittleFS.begin()) {
    LittleFS.info(fs_info);
    Serial.printf("LittleFS total space: %u bytes\n", fs_info.totalBytes);
    Serial.printf("LittleFS used space:  %u bytes\n", fs_info.usedBytes);
    Serial.printf("LittleFS free space:  %u bytes\n", fs_info.totalBytes - fs_info.usedBytes);
  } else {
    Serial.println("LittleFS mount failed");
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
  Serial.println("IP Address: " + WiFi.localIP().toString());

  // Mount LittleFS
  if (!LittleFS.begin()) {
    Serial.println("LittleFS mount failed");
    return;
  }

  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {

  printSystemInfo();
  server.handleClient();
}
