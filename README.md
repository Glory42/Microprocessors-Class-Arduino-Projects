<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Traffic Light Simulation with Pedestrian Crossing Button</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 0;
      padding: 20px;
      background-color: #f4f4f9;
      color: #333;
    }
    h1, h2 {
      color: #2c3e50;
    }
    .container {
      max-width: 900px;
      margin: auto;
      background: #fff;
      padding: 20px;
      border-radius: 8px;
      box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
    }
    ul {
      line-height: 1.6;
    }
    .components, .working, .intro {
      margin-bottom: 20px;
    }
    .components ul, .working ul {
      list-style-type: none;
      padding: 0;
    }
    .components li::before, .working li::before {
      content: '• ';
      color: #2980b9;
      font-weight: bold;
    }
    code {
      background-color: #e3e3e3;
      padding: 2px 4px;
      border-radius: 3px;
    }
    .highlight {
      background-color: #f39c12;
      padding: 5px;
      color: white;
      border-radius: 5px;
    }
  </style>
</head>
<body>
  <div class="container">
    <h1>Traffic Light Simulation with Pedestrian Crossing Button</h1>
    <p class="intro">
      This project demonstrates a basic traffic light system designed using the <strong>Arduino</strong> platform. The system operates with three LED lights (red, yellow, green) that simulate a standard traffic light sequence, with an additional feature for pedestrian crossing.
    </p>

    <h2>Key Features:</h2>
    <div class="features">
      <ul>
        <li><strong>Traffic Light Sequence:</strong></li>
        <ul>
          <li>Red light stays on for 5 seconds</li>
          <li>Yellow light stays on for 2 seconds</li>
          <li>Green light stays on for 5 seconds</li>
        </ul>
        <li><strong>Pedestrian Crossing:</strong></li>
        <ul>
          <li>A button simulates a pedestrian crossing request.</li>
          <li>When the button is pressed, the red light blinks, allowing pedestrian crossing.</li>
          <li>After blinking, the traffic lights return to normal operation.</li>
        </ul>
      </ul>
    </div>

    <h2>Components Used:</h2>
    <div class="components">
      <ul>
        <li>Arduino board (any compatible model)</li>
        <li>LEDs (Red, Yellow, Green)</li>
        <li>Resistors (appropriate values for LEDs)</li>
        <li>Push button (for pedestrian crossing)</li>
        <li>Breadboard and jumper wires</li>
      </ul>
    </div>

    <h2>How it Works:</h2>
    <div class="working">
      <ul>
        <li><strong>Normal Operation:</strong> The traffic lights follow a loop: <span class="highlight">Red for 5 seconds</span>, <span class="highlight">Yellow for 2 seconds</span>, and <span class="highlight">Green for 5 seconds</span>.</li>
        <li><strong>Pedestrian Request:</strong> When the pedestrian button is pressed, the red light blinks, signaling that pedestrians may cross. After blinking, the system resumes the normal traffic light sequence.</li>
      </ul>
    </div>

    <p class="closing">
      This project introduces students to basic circuit design and programming using Arduino, covering key concepts like input-output pins and digital signals.
    </p>
  </div>
</body>
</html>
