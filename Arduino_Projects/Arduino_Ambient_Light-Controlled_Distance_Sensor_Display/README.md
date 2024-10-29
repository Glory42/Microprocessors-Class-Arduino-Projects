# Ambient Light-Controlled Distance Sensor Display

This project demonstrates an ambient distance-based display system using an ultrasonic sensor and an RGB LED with the Arduino platform. The system detects object proximity and indicates distance ranges through color changes. A button allows switching between standard measurement mode and an alert mode.

## Key Features

### Distance-Based Color Indication
- **Normal Measurement Mode**:
  - Blue LED when an object is far (50+ cm).
  - Green LED when an object is moderately close (20-50 cm).
  - Red LED when an object is very close (under 20 cm).

### Alert Mode
- When the button is pressed, the system enters alert mode.
- If an object is within 20 cm in alert mode, the RGB LED will blink red to indicate proximity danger.
- The system returns to normal measurement mode with another button press.

## Components Used
- Arduino Uno (or any compatible model)
- RGB LED
- HC-SR04 Ultrasonic Distance Sensor
- Button (for mode switching)
- 220-ohm resistors (for LED connections)
- Breadboard and jumper wires

## How it Works
- **Normal Operation**: The system constantly measures distance and changes the RGB LED color based on proximity. Blue indicates safe distance, green indicates caution, and red indicates danger.
- **Alert Mode**: Activated by pressing the button. If an object is detected within a 20 cm range, the RGB LED blinks red to signal a proximity alert.
