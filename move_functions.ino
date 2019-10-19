#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *Left_Motor = AFMS.getMotor(1);
Adafruit_DCMotor *Right_Motor = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  AFMS.begin();  // create with the default frequency 1.6KHz
}

void move_robot(int how_much, int move_direction){
  /*
   * Moves robot forward or backwards, motor-shield needs to be 
   * initialized.
   */
    if(move_direction > 0){
      Left_Motor -> run(FORWARD);
      Right_Motor -> run(BACKWARD);
    } else {
      Left_Motor -> run(BACKWARD);
      Right_Motor -> run(FORWARD);
    }

  for (int i =0; i<50; i++) {
    Left_Motor->setSpeed(i);
    Right_Motor->setSpeed(i);  
    delay(2);
  }

  delay(how_much);
  
  for (int i=50; i!=0; i--) {
    Left_Motor->setSpeed(i);
    Right_Motor->setSpeed(i);
    delay(2);
  }
}

void turn_robot(int how_much, int move_direction){
   /*
   * Turns robot, motor-shield needs to be 
   * initialized.
   */
    if(move_direction > 0){
      Left_Motor -> run(FORWARD);
      Right_Motor -> run(FORWARD);
    } else {
      Left_Motor -> run(BACKWARD);
      Right_Motor -> run(BACKWARD);
    } 

    for (int i =0; i<50; i++) {
    Left_Motor->setSpeed(i);
    Right_Motor->setSpeed(i);  
    delay(2);
  }

  delay(how_much);
  
  for (int i=50; i!=0; i--) {
    Left_Motor->setSpeed(i);
    Right_Motor->setSpeed(i);
    delay(2);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
