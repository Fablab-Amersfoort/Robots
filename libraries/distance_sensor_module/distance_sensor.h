// library for HC-SR04 ultrasonice distance sensor
//
// pins: Vcc - Trig - Echo - Gnd

const int trigPin = 12;
const int echoPin = 8;

float duration;
float distance;

void Setup_Ultrasonic_Sensor() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float MeasureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;
  return distance;
}