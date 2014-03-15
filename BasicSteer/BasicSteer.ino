#include <Servo.h>
Servo steer;        // Create Servo object to control the servo

void setup() {
  steer.attach(9);
  steer.write(90);
  Serial.begin(9600);
} 

void loop(){
//  for(int i=30; i< 110; i++){
//    steer.write(i);
//    Serial.println(i);
//    delay(200);
//  }

steer.write(30);
delay(1000);
steer.write(75);
delay(1000);
steer.write(110);
delay(1000);
}
