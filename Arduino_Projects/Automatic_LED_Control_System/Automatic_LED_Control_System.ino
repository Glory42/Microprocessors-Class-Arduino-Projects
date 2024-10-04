const int RED_PIN = 9;
const int YELLOW_PIN = 10;
const int GREEN_PIN = 11;
const int BUTTON_PIN = 7;

const int RED_DURATION = 5000;
const int YELLOW_DURATION = 2000;
const int GREEN_DURATION = 5000;
const int BLINK_DURATION = 500;

enum TrafficState {
  RED,
  YELLOW,
  GREEN
};

enum TrafficDensity {
  LOW_DENSITY,
  MEDIUM_DENSITY,
  HIGH_DENSITY
};

TrafficState currentState = RED;
TrafficDensity currentDensity = MEDIUM_DENSITY;
unsigned long stateStartTime = 0;
unsigned long densityChangeTime = 0;
bool buttonPressed = false;
unsigned long pauseTime = 0; 

const unsigned long DENSITY_CHANGE_INTERVAL = 30000; 


const unsigned long DEBOUNCE_DELAY = 50;
int lastButtonState = HIGH;
int buttonState;
unsigned long lastDebounceTime = 0;

float getDensityFactor() {
  switch (currentDensity) {
    case LOW_DENSITY:
      return 0.8;
    case MEDIUM_DENSITY:
      return 1.0;
    case HIGH_DENSITY:
      return 1.5;
    default:
      return 1.0;
  }
}

void updateTrafficDensity() {
  unsigned long currentTime = millis();
  if (currentTime - densityChangeTime >= DENSITY_CHANGE_INTERVAL) {
    switch (currentDensity) {
      case LOW_DENSITY:
        currentDensity = MEDIUM_DENSITY;
        break;
      case MEDIUM_DENSITY:
        currentDensity = HIGH_DENSITY;
        break;
      case HIGH_DENSITY:
        currentDensity = LOW_DENSITY;
        break;
    }
    densityChangeTime = currentTime;
    Serial.print("Traffic Density changed to: ");
    Serial.println(currentDensity);
  }
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Traffic Light Controller Started");
}

void loop() {
  checkButton();
  updateTrafficDensity();

  if (buttonPressed) {
    Serial.println("Button pressed, entering pedestrian crossing mode");
    pedestrianCrossing();
    buttonPressed = false;

    
    stateStartTime = millis() - pauseTime; 
  } else {
    normalSequence();
  }
}

void checkButton() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        buttonPressed = true;
        Serial.println("Button press detected");
        
        
        pauseTime = millis() - stateStartTime;
      }
    }
  }

  lastButtonState = reading;
}

void pedestrianCrossing() {
  setAllLights(LOW);
  Serial.println("Pedestrian crossing sequence started");

  for (int i = 0; i < 5; i++) {
    digitalWrite(RED_PIN, HIGH);
    delay(BLINK_DURATION);
    digitalWrite(RED_PIN, LOW);
    delay(BLINK_DURATION);
  }

  Serial.println("Pedestrian crossing sequence ended");
}

void normalSequence() {
  unsigned long currentTime = millis();
  float densityFactor = getDensityFactor();

  switch (currentState) {
    case RED:
      setLight(RED_PIN);
      if (currentTime - stateStartTime >= RED_DURATION * densityFactor) {
        currentState = YELLOW;
        stateStartTime = currentTime;
        Serial.println("Changing to YELLOW");
      }
      break;

    case YELLOW:
      setLight(YELLOW_PIN);
      if (currentTime - stateStartTime >= YELLOW_DURATION) {
        currentState = GREEN;
        stateStartTime = currentTime;
        Serial.println("Changing to GREEN");
      }
      break;

    case GREEN:
      setLight(GREEN_PIN);
      if (currentTime - stateStartTime >= GREEN_DURATION * densityFactor) {
        currentState = RED;
        stateStartTime = currentTime;
        Serial.println("Changing to RED");
      }
      break;
  }
}

void setLight(int pin) {
  digitalWrite(RED_PIN, pin == RED_PIN ? HIGH : LOW);
  digitalWrite(YELLOW_PIN, pin == YELLOW_PIN ? HIGH : LOW);
  digitalWrite(GREEN_PIN, pin == GREEN_PIN ? HIGH : LOW);
  Serial.print("Light set: ");
  Serial.println(pin == RED_PIN ? "RED" : (pin == YELLOW_PIN ? "YELLOW" : "GREEN"));
}

void setAllLights(int state) {
  digitalWrite(RED_PIN, state);
  digitalWrite(YELLOW_PIN, state);
  digitalWrite(GREEN_PIN, state);
}
