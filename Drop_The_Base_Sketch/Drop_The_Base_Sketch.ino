void setup() {
  setupMotors();
  setupUltrasonic();
  Serial.begin(9600); //standard serial for debug/upload
  Serial1.begin(9600); //use Serial 1 for APC220, pin 19 is arduino rx and pin 18 is arduino tx, so connect 19 to tx on APC220 and 18 to rx on APC220
}

void loop() {
  // put your main code here, to run repeatedly:

}
