#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// ***** WiFi Settings *****
const char ssid[] = "Sigma Relay Controler"; // WiFi SSID
const char password[] = "sigmaelectronics.ir"; // WiFi Password

// ***** Server Settings *****
WiFiServer server(80);

// ***** HTML Content *****
String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html_1 = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'/><meta charset='utf-8'><style>body {font-size:140%;background-color: #112548;font-family:sans-serif} #main {display: table; margin: auto;  padding: 0 10px 0 10px; }  h2{text-align:center;color:#f89925; } h4{text-align:center; color:#f89925;} h5{text-align:center; color:#f89925} .button:hover{background-color: #f8cbcb;} .button { padding:15px 15px 15px 15px; width:100%;  background-color: #f89925; font-size: 100%;border: none;border-radius: 18px;font-family: sans-serif;}</style><title>Relay Control</title></head><body><div id='main'><h2>Relay Control</h2><br><h4>SigmaElectronics.ir</h4>";
String html_Plug = ""; // Dynamic content placeholder
String html_2 = "<form id='F1' action='PlugON'><input class='button' type='submit' value='LED ON' ></form><br>";
String html_3 = "<form id='F2' action='PlugOFF'><input class='button' type='submit' value='LED OFF' ></form><br>";
String html_4 = "</div></body></html>";

// ***** Pin Configuration *****
int Relay_Pin = 2; // Pin connected to the relay

// ***** Static IP Configuration *****
IPAddress PlugIP(192, 168, 4, 4);

// ***** Setup Function *****
void setup() {
  pinMode(Relay_Pin, OUTPUT); // Set relay pin as output

  // Configure and start WiFi Access Point
  WiFi.softAPConfig(PlugIP, PlugIP, IPAddress(255, 255, 255, 0)); // Static IP config
  WiFi.softAP(ssid, password); // Start the AP

  // Start the server
  server.begin();
}

// ***** Main Loop Function *****
void loop() {
  WiFiClient client = server.available(); // Check for incoming client
  if (!client) {
    return; // If no client, return
  }

  // Read client request
  String request = client.readStringUntil('\r');

  // ***** Handle Client Requests *****
  if (request.indexOf("PlugON") > 0) {
    digitalWrite(Relay_Pin, HIGH); // Turn relay ON
  } else if (request.indexOf("PlugOFF") > 0) {
    digitalWrite(Relay_Pin, LOW); // Turn relay OFF
  }

  // ***** Send Response to Client *****
  client.flush(); // Clear client buffer
  client.print(header);
  client.print(html_1);
  // client.print(html_Plug); // Uncomment if dynamic content is used
  client.print(html_2);
  client.print(html_3);
  client.print(html_4);

  delay(5); // Small delay to ensure the response is sent
}
