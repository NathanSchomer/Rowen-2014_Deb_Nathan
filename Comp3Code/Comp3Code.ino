//servo setup
#include <Servo.h>
Servo steerServo, rightDrive, leftDrive;
#define GO 300
#define STRAIGHT 55

void setup()
{
  //set and straighten wheels
  steerServo.attach(6);  
  steerServo.write(STRAIGHT);
  rightDrive.attach(10); 
  leftDrive.attach(9);
  //linear throttle curve on startup
  for(int i = 100; i < GO; i += 10)  
  {
    rightDrive.write(i);  
    leftDrive.write(i); 
    delay(75);
  } 
  Serial.begin(9600);
}

void loop()
{  
  leftDrive.write(GO); 
  rightDrive.write(GO);
  steerServo.write(STRAIGHT);
}

