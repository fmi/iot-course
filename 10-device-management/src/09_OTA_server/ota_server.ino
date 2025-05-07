/*
ESP32 OTA Server Example
=========================
This code demonstrates how to set up an OTA server on the ESP32.
It creates a web server that allows you to upload new firmware to the ESP32
via a web interface.

Steps:
1. Connect the ESP32 to a WiFi network.
2. Access the OTA web interface via the ESP32's IP address.
3. Upload the new firmware file (.bin) through the web interface.
*/

#include <WiFi.h>
#include <WebServer.h>
#include <Update.h>

// Replace with your network credentials
const char* ssid = "your SSID";
const char* password = "your SSID password";

// Create a web server on port 80
WebServer server(80);

// HTML page for the OTA update interface
const char* updatePage = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <title>ESP32 OTA Update</title>
  </head>
  <body>
    <h1>ESP32 OTA Update</h1>
    <form method="POST" action="/update" enctype="multipart/form-data">
      <input type="file" name="firmware">
      <input type="submit" value="Update">
    </form>
  </body>
</html>
)rawliteral";

// Handle the root URL
void handleRoot() {
  server.send(200, "text/html", updatePage);
}

// Handle the firmware upload
void handleUpdate() {
  HTTPUpload& upload = server.upload();

  if (upload.status == UPLOAD_FILE_START) {
    Serial.printf("Update Start: %s\n", upload.filename.c_str());
    if (!Update.begin(UPDATE_SIZE_UNKNOWN)) {
      Update.printError(Serial);
      return;
    }
  } else if (upload.status == UPLOAD_FILE_WRITE) {
    if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
      Update.printError(Serial);
    }
  } else if (upload.status == UPLOAD_FILE_END) {
    if (Update.end(true)) {
      Serial.printf("Update Success: %u bytes\n", upload.totalSize);
    } else {
      Update.printError(Serial);
    }
  }
}

// Handle the update result
void handleUpdateResult() {
  if (Update.hasError()) {
    server.send(200, "text/plain", "Update Failed");
  } else {
    server.send(200, "text/plain", "Update Successful. Rebooting...");
    delay(1000);
    ESP.restart();
  }
}

void setup() {
  // Start Serial communication
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Configure web server routes
  server.on("/", HTTP_GET, handleRoot);
  server.on("/update", HTTP_POST, handleUpdateResult, handleUpdate);

  // Start the web server
  server.begin();
  Serial.println("OTA Server started.");
}

void loop() {
  // Handle client requests
  server.handleClient();
  delay(5);
}