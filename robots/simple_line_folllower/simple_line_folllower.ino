#include "LDRLineSensor.h"
#include "MotorSturing.h"

#define LDR_LED 12          // LED for LDR sensing
#define BLINK_LED 13        // indicator LED
#define STEERDELAY 100      // Steering delay for line follower

int motorSpeed = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("FABLAB Robot line follower");
  Serial.println("Serial connection setup");
  pinMode(BLINK_LED, OUTPUT);
  pinMode(LDR_LED, OUTPUT);
  SetupMotorPins();
}

void loop() {
  motorSpeed = 35;
  digitalWrite(LDR_LED, HIGH);
  if ((LightOrDark(0)) && (LightOrDark(1))) {  // both sensors detect light
    digitalWrite(BLINK_LED, LOW);
    ControlMotor(0, motorSpeed);
    ControlMotor(1, motorSpeed);
  } else {
    if (!LightOrDark(0)) {  // left detects dark line
      digitalWrite(BLINK_LED, HIGH);
      ControlMotor(0, 0);           // stop left motor
      delay(STEERDELAY);            // wait
      ControlMotor(0, motorSpeed);  // start left motor
    }
    if (!LightOrDark(1)) {  // right detects dark line
      digitalWrite(BLINK_LED, HIGH);
      ControlMotor(1, 0);           // stop right motor
      delay(STEERDELAY);            // wait
      ControlMotor(1, motorSpeed);  // start right motor
    }
  }
}
