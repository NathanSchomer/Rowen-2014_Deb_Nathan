#include <Servo.h>
#include <LiquidCrystal.h>
//servo setup
Servo steerServo, rightDrive, leftDrive;
#define STOP_DELAY 100
#define TURN_DELAY 800 
#define GO_DELAY 400
#define WHITE_THRESH 992                      
#define STOP 90
#define GO 300
#define LEFT 110
#define RIGHT 30
#define STRAIGHT 70
//IR setup
int leftIR, rightIR;                            
//accelerometer setup
double x;  
double xx;  
double y;  
double yy;
double z;  
double zz;
double deg;
int tot; 
int ii; 
double avg;
//LCD setup
LiquidCrystal lcd(12, 11, 8, 5, 4, 3, 2); 
int backLight = 13; 
int sensorPin = A0; 
int ledPin = 13; 
int sensorValue = 0; 
int prevValue = 0;
int check = false;
int t = 0;

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
  //LCD setup
  pinMode(backLight, OUTPUT); 
  digitalWrite(backLight, HIGH); 
  lcd.begin(16,2); 
  lcd.clear();

  Serial.begin(9600);
}

int angle_check()
{
  x  = analogRead(3);  
  y  = analogRead(4);    
  z  = analogRead(5);

  xx = -1.0909*x+450;
  yy = 1.0286*y-360.51+12;
  zz = 0.9783*z - 239.18-3;
  deg = atan2(zz,yy);
  deg = deg*180/PI;
  deg = deg - 83;
  deg = deg*1.75;

  t++;
  //if going up incline: sum, count, and display deg
  if (deg > 9 && t>2 && t<5 )
  {
    leftDrive.write(STOP); 
    rightDrive.write(STOP);
    delay(150);
    int currTime = millis();
    while(millis() < (currTime + 250))
    {
      x  = analogRead(3);  
      y  = analogRead(4);    
      z  = analogRead(5);
      xx = -1.0909*x+450;
      yy = 1.0286*y-360.51+12;
      zz = 0.9783*z - 239.18-3;
      deg = atan2(zz,yy);
      deg = deg*180/PI;
      deg = deg - 83;
      deg = deg*1.75;
      tot += deg;
      lcd.setCursor(0,0);
      lcd.print("Inst. Angle: ");
      lcd.print(deg);
      lcd.setCursor(0,1);
      avg = tot / ii;
      lcd.print("Avg Angle: ");
      lcd.print(avg);
      ii++;
    }
    leftDrive.write(GO); 
    rightDrive.write(GO);
    delay(150);
  }
  leftDrive.write(GO); 
  rightDrive.write(GO);
  if (deg < 9 && t>45)
  {
    leftDrive.write(STOP); 
    rightDrive.write(STOP);
    delay(150);
    int currTime = millis();
    while(millis() < (currTime + 250))
    {
      x  = analogRead(3);  
      y  = analogRead(4);    
      z  = analogRead(5);
      xx = -1.0909*x+450;
      yy = 1.0286*y-360.51+12;
      zz = 0.9783*z - 239.18-3;
      deg = atan2(zz,yy);
      deg = deg*180/PI;
      deg = deg - 83;
      deg = deg*1.75;
      lcd.setCursor(0,0);
      lcd.print("Inst. Angle: ");
      lcd.print(deg);
    }
    leftDrive.write(GO); 
    rightDrive.write(GO);
    delay(150);
  }
  leftDrive.write(GO); 
  rightDrive.write(GO);
}

void loop()
{  
  //check IR sensors
  leftIR = analogRead(A1);  
  rightIR = analogRead(A0); 
  //left turn
  while(leftIR > WHITE_THRESH)
  {
    //    Serial.println("Go Left");
    steerServo.write(LEFT);
    delay(TURN_DELAY);
    leftDrive.write(GO); 
    rightDrive.write(GO);
    delay(GO_DELAY);
    leftIR = analogRead(A1);  
    rightIR = analogRead(A0);
  }
  //right turn
  while(rightIR > WHITE_THRESH)
  {
    //    Serial.println("Go Right");
    steerServo.write(RIGHT);
    delay(TURN_DELAY);
    leftDrive.write(GO); 
    rightDrive.write(GO);
    delay(GO_DELAY);
    leftIR = analogRead(A1);  
    rightIR = analogRead(A0);
  }
  //straight
  while(leftIR <= WHITE_THRESH && rightIR <= WHITE_THRESH)
  {
    leftDrive.write(GO); 
    rightDrive.write(GO);
    //    Serial.println("Go Straight");
    steerServo.write(STRAIGHT);
    leftIR = analogRead(A1);  
    rightIR = analogRead(A0);
  }
}








