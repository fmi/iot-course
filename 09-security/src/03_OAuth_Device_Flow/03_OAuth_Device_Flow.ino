/*
 * GitHub OAuth Device Flow Example for ESP32
 * -------------------------------------------
 * This program demonstrates how to use the GitHub OAuth Device Flow on an ESP32.
 * It connects to GitHub's OAuth server to request a device code, which the user
 * must enter on a browser to authorize the device. Once authorized, the ESP32
 * polls GitHub to obtain an access token, which is then used to make authenticated
 * API requests to GitHub (e.g., fetching user profile information).
 *
 * What to Expect:
 * 1. The ESP32 connects to WiFi.
 * 2. It requests a device code from GitHub.
 * 3. The Serial Monitor will display a URL and a user code.
 *    - Open the URL in a browser and enter the user code to authorize the device.
 * 4. The ESP32 polls GitHub for an access token.
 * 5. Once the access token is obtained, it makes an authenticated request to
 *    GitHub's API to fetch user information.
 * 6. The response from GitHub's API is printed to the Serial Monitor.
 *
 * How to Run:
 * 1. Replace `ssid` and `password` with your WiFi credentials.
 * 2. Replace `client_id` and `client_secret` with your GitHub OAuth App credentials.
 *    - Create a GitHub OAuth App at https://github.com/settings/developers.
 *    - Use "http://localhost" as the Homepage URL (callback URL is not required).
 * 3. Upload the code to your ESP32.
 * 4. Open the Serial Monitor at 115200 baud rate.
 * 5. Follow the instructions displayed on the Serial Monitor.
 *
 * Note:
 * - This code uses `client.setInsecure()` for simplicity. Replace it with proper
 *   certificate validation (`client.setCACert()`) in production.
 * - Ensure the `scope` matches the permissions you need (e.g., "read:user").
 * - For more info on the Flow: https://auth0.com/docs/get-started/authentication-and-authorization-flow/device-authorization-flow
 */

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h> // Include ArduinoJson library for JSON parsing

const char* ssid = "........"; // Replace with your WiFi SSID
const char* password = "......."; // Replace with your WiFi password

const char* github_oauth_server = "github.com";
const char* device_authorization_endpoint = "/login/device/code";
const char* token_endpoint = "/login/oauth/access_token";
const char* client_id = "Ov23liEaWnOnl8ROjhkF"; 
const char* client_secret = "0e5edcf8984992c7a6585609f941140b06f2d1ad"; 
const char* scope = "read:user"; 
WiFiClientSecure client;

String device_code;
String user_code;
String verification_url;
String access_token;

void setup() {
  Serial.begin(115200);
  delay(100);

  // Connect to WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  client.setInsecure(); // Use this only for testing; replace with proper certificate validation in production

  // Step 1: Request Device Code
  if (getDeviceCode()) {
    Serial.println("Please visit the following URL and enter the code:");
    Serial.println("URL: " + verification_url);
    Serial.println("Code: " + user_code);

    // Step 2: Poll for Access Token
    if (pollForAccessToken()) {
      Serial.println("Access token obtained successfully!");
      Serial.println("Access Token: " + access_token);

      // Step 3: Use the Access Token to make an authenticated request
      makeAuthenticatedRequest();
    } else {
      Serial.println("Failed to obtain access token.");
    }
  } else {
    Serial.println("Failed to get device code.");
  }
}

void loop() {
  // Do nothing
}

bool getDeviceCode() {
  Serial.println("Connecting to GitHub OAuth server...");
  if (!client.connect(github_oauth_server, 443)) {
    Serial.println("Connection to GitHub OAuth server failed!");
    return false;
  }

  String postData = "client_id=" + String(client_id) + "&scope=" + String(scope);
  Serial.println("POST Data: " + postData);

  client.println("POST " + String(device_authorization_endpoint) + " HTTP/1.1");
  client.println("Host: " + String(github_oauth_server));
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(postData.length());
  client.println();
  client.print(postData);

  String response = readResponse();
  Serial.println("Raw response: " + response);

  if (response.isEmpty()) {
    Serial.println("Empty response from server");
    return false;
  }

  // Parse URL-encoded response manually
  device_code = getValueFromResponse(response, "device_code");
  user_code = getValueFromResponse(response, "user_code");
  verification_url = getValueFromResponse(response, "verification_uri");
  verification_url = urlDecode(verification_url); // Decode the URL

  if (device_code.isEmpty() || user_code.isEmpty() || verification_url.isEmpty()) {
    Serial.println("Failed to parse required fields from response");
    return false;
  }

  Serial.println("Decoded URL: " + verification_url); // Print the decoded URL
  return true;
}

// Helper function to extract values from URL-encoded response
String getValueFromResponse(String response, String key) {
  int startIndex = response.indexOf(key + "=");
  if (startIndex == -1) {
    return "";
  }
  startIndex += key.length() + 1; // Move past "key="
  int endIndex = response.indexOf("&", startIndex);
  if (endIndex == -1) {
    endIndex = response.length();
  }
  return response.substring(startIndex, endIndex);
}

bool pollForAccessToken() {
  while (true) {
    delay(5000); // Poll every 5 seconds

    if (!client.connect(github_oauth_server, 443)) {
      Serial.println("Connection to GitHub OAuth server failed!");
      return false;
    }

    String postData = "client_id=" + String(client_id) + "&client_secret=" + String(client_secret) +
                      "&device_code=" + String(device_code) + "&grant_type=urn:ietf:params:oauth:grant-type:device_code";

    client.println("POST " + String(token_endpoint) + " HTTP/1.1");
    client.println("Host: " + String(github_oauth_server));
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(postData.length());
    client.println();
    client.print(postData);

    String response = readResponse();
    Serial.println("Raw response: " + response);

    if (response.isEmpty()) {
      Serial.println("Empty response from server");
      return false;
    }

    // Parse URL-encoded response manually
    access_token = getValueFromResponse(response, "access_token");
    String error = getValueFromResponse(response, "error");

    if (!access_token.isEmpty()) {
      return true; // Access token obtained successfully
    }

    if (!error.isEmpty() && error == "authorization_pending") {
      Serial.println("Authorization pending...");
      continue; // Keep polling
    }

    Serial.println("Error: " + error);
    return false; // Failed to obtain access token
  }
}

void makeAuthenticatedRequest() {
  if (!client.connect("api.github.com", 443)) {
    Serial.println("Connection to GitHub API failed!");
    return;
  }

  client.println("GET /user HTTP/1.1");
  client.println("Host: api.github.com");
  client.println("Authorization: Bearer " + access_token);
  client.println("User-Agent: ESP32");
  client.println("Connection: close");
  client.println();

  String response = readResponse();
  Serial.println("Response from GitHub API:");
  Serial.println(response);
}

String readResponse() {
  String response = "";
  while (client.connected() || client.available()) {
    if (client.available()) {
      response += client.readString();
    }
  }
  client.stop();
  return response;
}

String urlDecode(String encodedUrl) {
  String decodedUrl = "";
  char temp[] = "00"; // Temporary storage for percent-encoded characters

  for (unsigned int i = 0; i < encodedUrl.length(); i++) {
    if (encodedUrl[i] == '%') {
      if (i + 2 < encodedUrl.length()) {
        temp[0] = encodedUrl[i + 1];
        temp[1] = encodedUrl[i + 2];
        decodedUrl += (char)strtol(temp, NULL, 16); // Convert hex to char
        i += 2;
      }
    } else if (encodedUrl[i] == '+') {
      decodedUrl += ' '; // Replace '+' with space
    } else {
      decodedUrl += encodedUrl[i]; // Copy regular characters
    }
  }

  return decodedUrl;
}
