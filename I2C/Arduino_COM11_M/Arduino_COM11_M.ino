#include <Wire.h>
#define s1 4
#define s2 12

void setup() {
  Wire.begin();
  Serial.begin(9600);
}
void loop() {
  Wire.beginTransmission(s1);                           //    4- Red, 5- Red Yello, 8- Green, 7- Yellow
  Wire.write(4);
  Wire.endTransmission();
  getResponseS1();
  delay(100);
  Wire.beginTransmission(s2);
  Wire.write(8);
  Wire.endTransmission();
  getResponseS2();
  delay(2000);

  Wire.beginTransmission(s1);
  Wire.write(5);
  Wire.endTransmission();
  getResponseS1();
  delay(100);
  Wire.beginTransmission(s2);
  Wire.write(7);
  Wire.endTransmission();
  getResponseS2();  
  delay(2000);

  Wire.beginTransmission(s1);
  Wire.write(8);
  Wire.endTransmission();
  getResponseS1(); 
  delay(100);
  Wire.beginTransmission(s2);
  Wire.write(4);
  Wire.endTransmission();
  getResponseS2();  
  delay(2000);

  Wire.beginTransmission(s1);
  Wire.write(7);
  Wire.endTransmission();
  getResponseS1();
  delay(100);
  Wire.beginTransmission(s2);
  Wire.write(5);
  Wire.endTransmission();
  getResponseS2(); 
  delay(2000);

 
  Serial.println();
  delay(1000);
}

void getResponseS1(){
  Wire.requestFrom(s1, 15);
  while(Wire.available()){
    Serial.println((char)Wire.read());
  }
}

void getResponseS2(){
  Wire.requestFrom(s2, 15);
  while(Wire.available()){
    Serial.println((char)Wire.read());
  }
}
