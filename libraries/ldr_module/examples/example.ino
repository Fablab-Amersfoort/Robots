#include "LDRLineSensor.h"

// this sketch uses the first LDR connected to A0
// GND --[ 10k ]-+--[ LDR ]--- 5V
//               |
//               A0
//

void setup() {
  Serial.begin(9600);
}

void loop() {
  if ( LightOrDark(0) ) {
    Serial.println("licht");
  } else {
    Serial.println("donker");
  }
}