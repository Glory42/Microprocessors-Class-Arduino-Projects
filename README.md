# Traffic Light Simulation with Pedestrian Crossing Button

This project demonstrates a basic traffic light system designed using the Arduino platform. The system operates with three LED lights (red, yellow, green) that simulate a standard traffic light sequence, with an additional feature for pedestrian crossing.

## Key Features

- **Traffic Light Sequence**:
  - The red light stays on for 5 seconds.
  - The yellow light stays on for 2 seconds.
  - The green light stays on for 5 seconds.
- **Pedestrian Crossing**:
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

1. **Normal Operation**: The traffic lights follow a loop: Red for 5 seconds, Yellow for 2 seconds, Green for 5 seconds.
2. **Pedestrian Request**: When the pedestrian button is pressed, the red light will blink to signal the crossing, and after that, the traffic lights return to their regular sequence.

## Getting Started

1. Clone this repository to your local machine.
2. Open the Arduino IDE and load the project file.
3. Connect your Arduino board and upload the sketch.
4. Set up the circuit according to the provided schematic.
5. Power on the Arduino and observe the traffic light simulation in action!

## Code Structure

- `traffic_light_simulation.ino`: Main Arduino sketch file containing the entire code for the project.
- `README.md`: This file, containing project documentation.

## Contributing

Contributions to improve the project are welcome. Please feel free to fork the repository, make changes, and submit a pull request. For major changes, please open an issue first to discuss what you would like to change.


## Acknowledgments

- Arduino community for their excellent documentation and examples.
- Contributors who have helped to improve and maintain this project.

For questions, issues, or suggestions, please open an issue on the GitHub repository.

  
</body>
</html>
