# Traffic Light Simulation with Pedestrian Crossing Button

This project demonstrates a basic traffic light system designed using the Arduino platform. The system operates with three LED lights (red, yellow, green) that simulate a standard traffic light sequence, with an additional feature for pedestrian crossing.

## Key Features

### Traffic Light Sequence
- The red light stays on for 5 seconds.
- The yellow light stays on for 2 seconds.
- The green light stays on for 5 seconds.

### Pedestrian Crossing
- A button is added to simulate a pedestrian crossing request.
- When the button is pressed, the red light blinks to indicate pedestrian crossing.
- After the pedestrian crossing sequence, the traffic lights return to normal operation.

## Components Used
- Arduino board (any compatible model)
- LEDs (Red, Yellow, Green)
- Resistors (appropriate values for LEDs)
- Push button (for pedestrian crossing)
- Breadboard and jumper wires

## How it Works
- **Normal Operation**: The traffic lights follow a loop: Red for 5 seconds, Yellow for 2 seconds, Green for 5 seconds.
- **Pedestrian Request**: When the pedestrian button is pressed, the red light will blink to signal the crossing, and after that, the traffic lights return to their regular sequence.
