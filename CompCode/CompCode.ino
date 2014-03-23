//Servo setup
#include <Servo.h> //servo library

Servo steerServo, rightDrive, leftDrive; 

#define STOP_DELAY 1000 
#define BACK_DELAY 300
#define TURN_DELAY 150
#define GO_DELAY 400
#define WHITE_THRESH 992                      
#define BACK 70
#define STOP 90
#define GO 300
#define LEFT 180
#define RIGHT 10
#define STRAIGHT 70

int leftIR, rightIR;                        

void setup()
{
  steerServo.attach(9);                         //set wheels to pins and start straight
  steerServo.write(STRAIGHT);   
  
rightDrive.attach(5); 
  leftDrive.attach(6);

  for(int i = 100; i < GO; i += 10)           //linear throttle curve on startup
  {
    rightDrive.write(i);  
    leftDrive.write(i); 
    delay(75);
  } 
  Serial.begin(9600);
}

void loop()
{  
  //check IR sensors
  leftIR = analogRead(A1);  
  rightIR = analogRead(A2); 
  //left turn
  while(leftIR > WHITE_THRESH)
  {
    Serial.println("Go Left");
    steerServo.write(RIGHT);
    delay(TURN_DELAY);
    leftDrive.write(BACK); 
    rightDrive.write(BACK);
    delay(BACK_DELAY);
    steerServo.write(LEFT);
    delay(TURN_DELAY);
    leftDrive.write(GO); 
    rightDrive.write(GO);
    delay(GO_DELAY);
    leftIR = analogRead(A1);  
    rightIR = analogRead(A2);
  }
  //right turn
  while(rightIR > WHITE_THRESH)
  {
    Serial.println("Go Right");
    steerServo.write(LEFT);
    delay(TURN_DELAY);
    leftDrive.write(BACK); 
    rightDrive.write(BACK);
    delay(BACK_DELAY);
    steerServo.write(RIGHT);
    delay(TURN_DELAY);
    leftDrive.write(GO); 
    rightDrive.write(GO);
    delay(GO_DELAY);
    leftIR = analogRead(A1);  
    rightIR = analogRead(A2);
  }
  //straight
  while(leftIR <= WHITE_THRESH && rightIR <= WHITE_THRESH)
  {
    leftDrive.write(GO); 
    rightDrive.write(GO);
    Serial.println("Go Straight");
    steerServo.write(STRAIGHT);
    leftIR = analogRead(A1);  
    rightIR = analogRead(A2);
  }
}


