# Plant Monitoring and Alert System

This project implements a plant monitoring system using the Arduino platform, equipped with sensors to measure environmental conditions and send updates via Telegram. The system provides real-time data about temperature, humidity, light levels, and soil moisture to help ensure optimal plant care.

## Key Features

### Real-Time Monitoring
- **Temperature and Humidity**: Uses a DHT11 sensor to measure the temperature and humidity levels.
- **Light Level**: Measures ambient light using an LDR (Light Dependent Resistor).
- **Soil Moisture**: Monitors soil moisture levels with an analog moisture sensor.

### Telegram Notifications
- Automatically sends periodic updates to a designated Telegram chat.
- Alerts for specific soil moisture conditions:
  - Sensor disconnected or not in soil.
  - Dry soil.
  - Ideal soil moisture.
  - Overwatered soil.

### Message Encoding
- Ensures proper handling of spaces and special characters in messages using URL encoding.

## Components Used
- **Arduino Board** (e.g., ESP32 for WiFi capabilities)
- **DHT11 Sensor** for temperature and humidity measurement.
- **LDR Sensor** for light level measurement.
- **Soil Moisture Sensor** for monitoring soil condition.
- Resistors and connecting wires.
- WiFi connection for Telegram communication.

## How It Works
1. **WiFi Connection**: Connects to the specified WiFi network using provided credentials.
2. **Sensor Readings**: Collects data from the DHT11, LDR, and soil moisture sensors.
3. **Data Validation**: Ensures sensor readings are valid before processing.
4. **Message Generation**: Formats a comprehensive update message including:
   - Temperature.
   - Humidity.
   - Light Level.
   - Soil Moisture and corresponding status message.
5. **Telegram API**: Sends the formatted message to a Telegram bot using its API.

## Telegram Integration
- The system connects to the Telegram API securely over HTTPS.
- A bot token and chat ID are required to send messages.
- Messages include alerts for soil conditions and general updates for plant monitoring.

## Code Highlights
- **WiFi Connection**: Ensures reliable connection to the network.
- **Telegram API Integration**: Handles message formatting and secure communication with Telegram servers.
- **Soil Moisture Alerts**: Provides actionable feedback based on soil conditions.

## How to Use
1. **Hardware Setup**:
   - Connect the DHT11, LDR, and soil moisture sensors to the Arduino.
   - Use appropriate resistors for sensors.
2. **Configure WiFi**:
   - Replace `ssid` and `password` in the code with your WiFi credentials.
3. **Telegram Setup**:
   - Create a Telegram bot and obtain its token.
   - Replace `botToken` and `chatID` with your bot's token and your chat ID.
4. **Upload Code**:
   - Upload the provided code to your Arduino board.
5. **Monitor Updates**:
   - Receive updates every 30 seconds (adjustable in the code) directly on Telegram.

## Future Improvements
- Add more sensor types for extended monitoring (e.g., pH sensor).
- Implement dynamic update intervals.
- Create a web or mobile dashboard for better data visualization.

Enjoy monitoring your plants with ease! 🌱
