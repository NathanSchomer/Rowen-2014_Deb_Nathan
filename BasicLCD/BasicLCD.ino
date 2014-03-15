#include <LiquidCrystal.h>

// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(12, 11, 10, 7, 4, 3, 2);
int backLight = 13;    // pin 13 will control the backlight
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int prevValue = 0;

void setup()
{
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                  // start with a blank screen
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("HI DEB");    // change this text to whatever you like. keep it clean.
  lcd.setCursor(0,1);           // set cursor to column 0, row 1
  lcd.print("This is HamBot");
  Serial.begin(9600);
}

void loop()
{
//    lcd.clear();
////   prevValue = sensorValue;
//   sensorValue = analogRead(sensorPin);
////   lcd.setCursor(0,0);
////   lcd.print(prevValue);
////   lcd.setCursor(1,0);
////   lcd.print(sensorValue);
//     lcd.setCursor(0,0);
//     lcd.print(sensorValue);
//     delay(300);

  /*gyroValue = analogRead(A0) >> 2;   // Work with 8 most significant bits!
 
  gyroRate = (gyroValue - offset) * 5.5; // Sensitivity has been found trial/error
  angle += gyroRate / 100.0;
 
  Serial.print(angle);
  Serial.print("\n");
 
  delay(200);
     
     
}

/*
unsigned char gyroValue = 0;      
unsigned char offset = 136;
float angle = 0;
float gyroRate;
 
void setup() {
  Serial.begin(9600); 
}
 
void loop() {
  gyroValue = analogRead(A0) >> 2;   // Work with 8 most significant bits!
 
  gyroRate = (gyroValue - offset) * 5.5; // Sensitivity has been found trial/error
  angle += gyroRate / 100.0;
 
  Serial.print(angle);
  Serial.print("\n");
 
  delay(10);                     
}
*/
}
