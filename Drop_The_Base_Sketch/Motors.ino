#define FRONT_LEFT_MOTOR 2 //use pin 2 for in1 and pin 3 for in2
#define FRONT_RIGHT_MOTOR 4
#define BACK_LEFT_MOTOR 6
#define BACK_RIGHT_MOTOR 8

#define COAST 0
#define REVERSE 1
#define FOREWARD 2
#define BRAKE 3

void setupMotors() {
  pinMode(FRONT_LEFT_MOTOR, OUTPUT); //set all motor pins to output
  pinMode(FRONT_LEFT_MOTOR+1, OUTPUT);
  pinMode(FRONT_RIGHT_MOTOR, OUTPUT);
  pinMode(FRONT_RIGHT_MOTOR+1, OUTPUT);
  pinMode(BACK_LEFT_MOTOR, OUTPUT);
  pinMode(BACK_LEFT_MOTOR+1, OUTPUT);
  pinMode(BACK_RIGHT_MOTOR, OUTPUT);
  pinMode(BACK_RIGHT_MOTOR+1, OUTPUT);
}

void setMotor(int motor, int modeHigh, int modeLow, int duty) {
  if(modeHigh%2==modeLow%2) {
    digitalWrite(motor+1, modeLow%2); //no pwm if they are the same
  } else {
    if(modeHigh%2==1) {
      analogWrite(motor+1, duty);
    }
    if(modeHigh%2==0) {
      analogWrite(motor+1, 255-duty); //invert if modeLow has a 1 (for some reason)
    }
  }
  
  if(modeHigh/2==modeLow/2) { //same code but for other pin
    digitalWrite(motor, modeHigh/2);
  } else {
    if(modeHigh/2==1) {
      analogWrite(motor, duty);
    }
    if(modeHigh/2==0) {
      analogWrite(motor, 255-duty);
    }
  }
}
