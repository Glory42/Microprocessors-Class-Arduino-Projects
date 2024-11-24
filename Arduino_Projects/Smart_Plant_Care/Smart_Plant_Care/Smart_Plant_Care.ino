#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <DHT.h>
#include <ArduinoJson.h>

// WiFi Credentials
const char* ssid = "*********";         // Wifi name
const char* password = "*******";      // Wifi password

// Telegram Bot Token
const char* botToken = "***********"; // telegram bot token

// Telegram Chat ID 
const char* chatID = "*********"; // telegram chat ID

// DHT Sensor Setup
#define DHT_PIN 25
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// Sensor Pins
#define LDR_PIN 39
#define MOISTURE_PIN 34

WiFiClientSecure client;

void sendTelegramMessage(String message) {
  String encodedMessage = "";
  // Encode the message to handle spaces and special characters
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    if (c == ' ') {
      encodedMessage += "%20";  // Encode space as %20
    } else if (c == ':') {
      encodedMessage += "%3A";  // Encode colon as %3A
    } else if (c == '\n') {
      encodedMessage += "%0A";  // Encode newline as %0A
    } else {
      encodedMessage += c;  // Keep other characters as they are
    }
  }

  // Connect to Telegram API and send the message
  if (client.connect("api.telegram.org", 443)) {
    String url = "/bot" + String(botToken) + "/sendMessage?chat_id=" + String(chatID) + "&text=" + encodedMessage;
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: api.telegram.org\r\n" +
                 "Connection: close\r\n\r\n");
    Serial.println("Message sent: " + message);
  } else {
    Serial.println("Failed to connect to Telegram API");
  }
}

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Allow client to access Telegram's server
  client.setInsecure();

  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  // Read sensor data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int lightLevel = analogRead(LDR_PIN);
  int soilMoisture = analogRead(MOISTURE_PIN);

  // Check if data is valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read sensors");
    return;
  }

  // Check soil moisture level and generate corresponding message
  String soilMessage = "";
  if (soilMoisture >= 3000) {
    soilMessage = "⚠️ Sensor is not in soil or Sensor disconected!";
  } else if (soilMoisture >= 1000 && soilMoisture < 3000) {
    soilMessage = "⚠️ Soil is dry!";
  } else if (soilMoisture >= 370 && soilMoisture < 1000) {
    soilMessage = "🚨 Soil is humid! great for ideal conditions";
  } else if (soilMoisture < 370){
    soilMessage = "⚠️ Soil is too wet!";
  }

  // Create message
  String message = "🌿 Plant Care Update:\n";
  message += "🌡 Temperature: " + String(temperature) + " °C\n";
  message += "💧 Humidity: " + String(humidity) + " %\n";
  message += "☀ Light Level: " + String(lightLevel) + "\n";
  message += "🌱 Soil Moisture: " + String(soilMoisture) + "\n";
  message += soilMessage;  // Add soil moisture message

  // Send message via Telegram
  sendTelegramMessage(message);

  // Wait 30 seconds before sending the next update for testing
  delay(30000); // 30 seconds for testing
}



