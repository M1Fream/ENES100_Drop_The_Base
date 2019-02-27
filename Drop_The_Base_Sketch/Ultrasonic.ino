#define LEFT_TRIG 9
#define LEFT_ECHO 10
#define RIGHT_TRIG 11
#define RIGHT_ECHO 12

void setupUltrasonic() {
  pinMode(LEFT_TRIG, OUTPUT);
  pinMode(LEFT_ECHO, INPUT);
  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(RIGHT_ECHO, INPUT);
}
float getDist(int trig, int echo) { //distance in cm
  //noInterrupts(); //might want that for precise timing
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  float distance = duration*(0.0343/2);
  
  //interrupts(); //TURN INTERUPTS BACK ON IF YOU TURN THEM OFF
  
  return distance;
}
