

///*
//  Analog Input
// Demonstrates analog input by reading an analog sensor on analog pin 0 and
// turning on and off a light emitting diode(LED)  connected to digital pin 13. 
// The amount of time the LED will be on and off depends on
// the value obtained by analogRead(). 
// 
// The circuit:
// * Potentiometer attached to analog input 0
// * center pin of the potentiometer to the analog pin
// * one side pin (either one) to ground
// * the other side pin to +5V
// * LED anode (long leg) attached to digital output 13
// * LED cathode (short leg) attached to ground
// 
// * Note: because most Arduinos have a built-in LED attached 
// to pin 13 on the board, the LED is optional.
// 
// 
// Created by David Cuartielles
// modified 30 Aug 2011
// By Tom Igoe
// 
// This example code is in the public domain.
// 
// http://arduino.cc/en/Tutorial/AnalogInput
// 
// */
//
//int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
//int sensorValue = 0;  // variable to store the value coming from the sensor
//
//void setup() {
//  // declare the ledPin as an OUTPUT:
//  Serial.begin(9600);
//}
//
//void loop() {
//  sensorValue = analogRead(sensorPin);    
//  Serial.println(sensorValue);
//  delay(2000);  
//}

/* Keep track of gyro angle over time
 * Connect Gyro to Analog Pin 0
 *
 * Sketch by eric barch / ericbarch.com
 * v. 0.1 - simple serial output
 *
 */
 
#include <Servo.h>
Servo leftDrive, rightDrive, steerServo;

int gyroPin = 0;               //Gyro is connected to analog pin 0
float gyroVoltage = 4.26;         //Gyro is running at 5V
float gyroZeroVoltage = 2.38;   //Gyro is zeroed at 2.5V
float gyroSensitivity = .2;  //Our example gyro is 7mV/deg/sec                                               noise control
float rotationThreshold = 1;   //Minimum deg/sec to keep track of - helps with gyro drifting                  angle control

float currentAngle = 0;          //Keep track of our current angle

void setup() {
  Serial.begin (9600);
  
  steerServo.attach(9);  steerServo.write(70);    //straighten front wheels
  rightDrive.attach(5); leftDrive.attach(6);
  for(int i = 100; i < 180; i += 10){rightDrive.write(i);  leftDrive.write(i); delay(75);} //linear throttle curve on startup
  
}

void loop() {
  //This line converts the 0-1023 signal to 0-5V
  float gyroRate = (analogRead(gyroPin) * gyroVoltage) / 1023;

  //This line finds the voltage offset from sitting still
  gyroRate -= gyroZeroVoltage;

  //This line divides the voltage we found by the gyro's sensitivity
  gyroRate /= gyroSensitivity;

  //Ignore the gyro if our angular velocity does not meet our threshold
  if (gyroRate >= rotationThreshold || gyroRate <= -rotationThreshold) {
    //This line divides the value by 100 since we are running in a 10ms loop (1000ms/10ms)
    gyroRate /= 100;
    currentAngle += gyroRate;
  }

  //Keep our angle between 0-359 degrees
  if (currentAngle < 0)
    currentAngle += 360;
  else if (currentAngle > 359)
    currentAngle -= 360;

  //DEBUG
  Serial.println(360 - currentAngle);

  delay(10);
}
