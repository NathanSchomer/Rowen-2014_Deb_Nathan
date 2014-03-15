#include <Servo.h>
Servo leftDrive;        // Create Servo object to control the servo
Servo rightDrive;
Servo steer;

void setup() {
 rightDrive.attach(5); 
 leftDrive.attach(6);
 steer.attach(9);
 steer.write(70);
} 

void loop() { 
  rightDrive.write(90); //stop
  leftDrive.write(90);

  
}
