#include "distance_sensor.h"

void setup() {
  Serial.begin(9600);
  Setup_Ultrasonic_Sensor();
}

void loop() {
  Serial.println(MeasureDistance());
  delay(500);
}