#include "LDRLineSensor.h"
#include "MotorSturing.h"

#define BLINK_DELAY 500     // blink delay
#define DEBOUNCE_DELAY 450  // debounce for keypress
#define MOTOR_DELAY 1000    // motor switch delay
#define LDR_LED 12          // LED for LDR sensing
#define BLINK_LED 13        // indicator LED

bool lastButtonState = false;
long LastBlinkTime = 0;
long LastMotorSwitchTime = 0;
const int KeyPin = A5;
int STATE = 0;
int lastActivityTime = 0;
int motorSpeed = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BLINK_LED, OUTPUT);
  pinMode(LDR_LED, OUTPUT);
  pinMode(KeyPin, INPUT_PULLUP);
  SetupMotorPins();
}

void KnipperLed(int pin) {
  // blinks the LED at pin given
  if ((millis() - LastBlinkTime) > BLINK_DELAY) {
    digitalWrite(pin, !digitalRead(pin));
    LastBlinkTime = millis();
  }
}

void MotorForwardBackward(int motor) {
  // moves motor forward and backward
  if ((millis() - LastMotorSwitchTime) > MOTOR_DELAY) {
    motorSpeed = -motorSpeed;
    ControlMotor(motor, motorSpeed);
    LastMotorSwitchTime = millis();
  }
}

void loop() {
  bool readButton;
  readButton = digitalRead(KeyPin);
  if (!readButton)  // Input pulled low to GND. Button pressed.
  {
    if (!lastButtonState) {
      if (millis() - lastActivityTime > DEBOUNCE_DELAY) {
        lastActivityTime = millis();
        STATE += 1;
        Serial.println(STATE);
        digitalWrite(BLINK_LED, LOW);
        digitalWrite(LDR_LED, LOW);
      }
    }
    lastButtonState = HIGH;
  }
  else {
    if (lastButtonState){
      lastButtonState = LOW;
    }
  }
  if (STATE == 1) {
    KnipperLed(BLINK_LED);
  }
  if (STATE == 2) {
    digitalWrite(LDR_LED, HIGH);
    if (LightOrDark(0)) {
      Serial.println(ShowLDRValue(0));
      Serial.println(" licht");
      digitalWrite(BLINK_LED, HIGH);
    } else {
      Serial.println(ShowLDRValue(0));
      Serial.println(" donker");
      digitalWrite(BLINK_LED, LOW);
    }
    digitalWrite(LDR_LED, LOW);
  }
  if (STATE == 3) {
    digitalWrite(LDR_LED, HIGH);
    if (LightOrDark(1)) {
      Serial.println(ShowLDRValue(1));
      Serial.println(" licht");
      digitalWrite(BLINK_LED, HIGH);
    } else {
      Serial.println(ShowLDRValue(1));
      Serial.println(" donker");
      digitalWrite(BLINK_LED, LOW);
    }
    digitalWrite(LDR_LED, LOW);
  }
  if (STATE == 4) {
    StopMotor(1);
    MotorForwardBackward(0);
  }
  if (STATE == 5) {
    StopMotor(0);
    MotorForwardBackward(1);
  }
  if (STATE == 6) {
    ControlMotor(0, motorSpeed);
    ControlMotor(1, motorSpeed);
  }
  if (STATE == 7) {
    ControlMotor(0, -motorSpeed);
    ControlMotor(1, -motorSpeed);
  }
  if (STATE == 8) {
    if ((millis() - LastMotorSwitchTime) > MOTOR_DELAY) {
      motorSpeed = -motorSpeed;
      ControlMotor(0, motorSpeed);
      ControlMotor(1, motorSpeed);
      LastMotorSwitchTime = millis();
    }
  }
  if (STATE == 9) {
    StopMotor(0);
    StopMotor(1);
    STATE = 0;
  }
}
