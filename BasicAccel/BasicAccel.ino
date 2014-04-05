double x;  double xx;  
double y;  double yy;
double z;  double zz;
double deg;
 
void setup()
{ 
  Serial.begin(9600);
}
void loop()
{
  x  = analogRead(3);  
  y  = analogRead(4);    
  z  = analogRead(5);
//  
  xx = -1.0909*x+450;
  yy = 1.0286*y-360.51+12;
  zz = 0.9783*z - 239.18-3;
  deg = atan2(zz,yy);
  deg = deg*180/PI;
  deg = deg - 83;
  deg = deg*1.75;
  Serial.println(deg);
//  Serial.print("X = ");  
//  Serial.print(xx);
//  Serial.print("\t");
//  Serial.print("Y = "); 
//  Serial.print(yy);
//  Serial.print("\t");
//  Serial.print("Z = ");  
//  Serial.print(zz);
//  Serial.println();
  delay(300);
}
