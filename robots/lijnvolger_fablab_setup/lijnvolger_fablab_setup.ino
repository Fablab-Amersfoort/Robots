#include "LDRLineSensor.h"
#include "MotorSturing.h"

#define BLINK_DELAY 500     // blink delay
#define DEBOUNCE_DELAY 150  // debounce for keypress
#define LONGPRESS_TIME 750  // time for press to be detected as 'long'
#define MOTOR_DELAY 1000    // motor switch delay
#define LDR_LED 12          // LED for LDR sensing
#define BLINK_LED 13        // indicator LED
#define STEERDELAY 100      // Steering delay for line follower

long LastBlinkTime = 0;
long LastMotorSwitchTime = 0;
const int KeyPin = A5;
int STATE = 0;
int lastActivityTime = 0;
int motorSpeed = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial connection setup");
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

void TestStateMachine() {
  if (STATE == 1) {
    KnipperLed(BLINK_LED);
  }
  if (STATE == 2) { // left LDR test
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
  if (STATE == 3) { // right LDR test
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

void LineFollower() {
  motorSpeed = 40;
  digitalWrite(LDR_LED, HIGH);
  if ((LightOrDark(0)) && (LightOrDark(1))) {
    ControlMotor(0, motorSpeed);
    ControlMotor(1, motorSpeed);
  } else {
    if (!LightOrDark(0)) {  // left detects dark line
      ControlMotor(0, 0);   // stop left motor
      delay(STEERDELAY);    // wait
      ControlMotor(0, motorSpeed);  // start left motor
    }
    if (!LightOrDark(1)) {  // right detects dark line
      ControlMotor(1, 0);
      delay(STEERDELAY);
      ControlMotor(1, motorSpeed);
    }
  }
}

bool TestMode = false;
bool lastButtonState = false;
bool LongPressActive = false;

void loop() {
  if (!digitalRead(KeyPin))  // Input pulled low to GND. Button pressed.
  {
    if (!lastButtonState) {
      if ((millis() - lastActivityTime) > DEBOUNCE_DELAY) {
        lastActivityTime = millis();
      }
    } else if ((millis() - lastActivityTime > LONGPRESS_TIME) && (!LongPressActive))  // Button long press
    {
      LongPressActive = true;
      STATE = 0;
      Serial.println("Long press");
      TestMode = !TestMode;
      if (TestMode) {
        Serial.println("Test mode active");
      }
    }
    lastButtonState = HIGH;
  } else {
    if (lastButtonState) {
      if (LongPressActive) {
        LongPressActive = false;
      } else {
        if ((millis() - lastActivityTime) > DEBOUNCE_DELAY) {
          Serial.println("short press");
          STATE += 1;
          if (!TestMode) {
            if (STATE > 1) {
              STATE = 0;
            }
          }
          Serial.println(STATE);
          digitalWrite(BLINK_LED, LOW);
          digitalWrite(LDR_LED, LOW);
        }
      }
      lastButtonState = LOW;
    }
  }
  if (TestMode) {
    TestStateMachine();
  } else {
    if (STATE == 1) {
      LineFollower();
    } else { KnipperLed(BLINK_LED); }
  }
}
