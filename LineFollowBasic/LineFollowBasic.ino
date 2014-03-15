/* 
Nathan Schomer
Deb Hudson

This is our code.

Blah blah blah.

Distance from bottom of steering plate to ground of the HamBot. */
 
#define WHITE_THRESH 987

int sensorPin = A1;    // select the input pin for the potentiometer
int sensorPin2 = A2;
int sensorValueL = 0;  // variable to store the value coming from the sensor
int sensorValueR = 0;

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  sensorValueL = analogRead(sensorPin2);
  sensorValueR = analogRead(sensorPin);
  
  if(sensorValueL > WHITE_THRESH)
  {
    Serial.println("You're off the fucking line");
  } 
  
  else if(sensorValueR > WHITE_THRESH)
  {
    Serial.println("RIGHT");
  }
  else if(sensorValueL <= WHITE_THRESH && sensorValueR <= WHITE_THRESH)
  {
   Serial.println("GOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
  }
    //Serial.println(sensorValue);
  delay(200); 
}
