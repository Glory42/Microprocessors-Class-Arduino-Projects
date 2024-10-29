// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const int buttonPin = 7;

// Constants
const unsigned long BLINK_INTERVAL = 100;  // 100ms for rapid blinking
const float MAX_DISTANCE = 100.0;  // Maximum distance in cm
const float CLOSE_DISTANCE = 20.0;  // Distance threshold for close objects
const float MEDIUM_DISTANCE = 50.0;  // Distance threshold for medium objects

// Variables
int mode = 0;  // 0 for Normal Measurement Mode, 1 for Alert Mode
unsigned long lastBlinkTime = 0;
bool ledState = false;
float distance = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  distance = measureDistance();
  
  if (digitalRead(buttonPin) == LOW) {
    delay(50);  // Debounce
    if (digitalRead(buttonPin) == LOW) {
      mode = 1 - mode;  // Toggle mode
      while (digitalRead(buttonPin) == LOW);  // Wait for button release
    }
  }
  
  if (mode == 0) {
    normalMode();
  } else {
    alertMode();
  }
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Mode: ");
  Serial.println(mode == 0 ? "Normal" : "Alert");
  
  delay(50);  // Short delay for stability
}

float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void normalMode() {
  if (distance > MEDIUM_DISTANCE) {
    setColor(0, 0, 255);  // Blue for far
  } else if (distance > CLOSE_DISTANCE) {
    setColor(0, 255, 0);  // Green for medium
  } else {
    setColor(255, 0, 0);  // Red for close
  }
}

void alertMode() {
  if (distance <= CLOSE_DISTANCE) {
    unsigned long currentTime = millis();
    if (currentTime - lastBlinkTime >= BLINK_INTERVAL) {
      ledState = !ledState;
      setColor(ledState ? 255 : 0, 0, 0);  // Blink red
      lastBlinkTime = currentTime;
    }
  } else {
    setColor(0, 0, 0);  // LED off if not close
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}