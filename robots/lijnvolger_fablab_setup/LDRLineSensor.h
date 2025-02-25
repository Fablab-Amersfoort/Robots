// LDR library for line follower
//
// Up to 4 LDRs can be connected as follows
//
// GND --[ 10k ]-+--[ LDR ]--- 5V
//               |
//               Analog pin
//
// Set up LDR pins:

int LDRpin[] = {A0, A1, A2, A3};

// set up initial values

#define LDRTHRESHOLD 360

int LDRValue[] = { 0, 0, 0, 0};

// calibrate these values as follows:
// - measure value in darkness (Vd)
// - measure value in full light (Vl)
// - threshold = (Vl - Vd) / 2

int LDRthreshold[] = { 200, 250, 500, 500};

int ShowLDRValue(int LDR) {
  return analogRead(LDRpin[LDR]);
}

bool LightOrDark(int LDR) {
  return ( (analogRead(LDRpin[LDR])) > LDRthreshold[LDR] ); // light = true, dark = false
}
