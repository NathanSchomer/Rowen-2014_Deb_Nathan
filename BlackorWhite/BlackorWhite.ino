/* 
Nathan Schomer
Deb Hudson

This is our code.

Blah blah blah.

Distance from bottom of steering plate to ground of the HamBot. */
 
#define WHITE_THRESH 987

int sensorPin = A2;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 1;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);

  
  
//  if(sensorValue <= WHITE_THRESH){
//    Serial.println("white");
//  } 
//  
//  else if(sensorValue > WHITE_THRESH){
//    Serial.println("BLACK");
//  }

Serial.println(sensorValue);
delay(200); 
}
