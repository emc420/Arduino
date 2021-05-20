/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
  int blue=0;
  int green=0; 
  int red=0; 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  Serial.print("Your text");
  Serial.println("Emc2"); // new line
 
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
   red = digitalRead(13);
   blue = digitalRead(8);
   green =digitalRead(12);
   Serial.print("Red");
   Serial.println(red); 
   Serial.print("Blue");
   Serial.println(blue);
   Serial.print("Green");
   Serial.println(green);
  delay(1000);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
      red = digitalRead(13);
       blue = digitalRead(8);
       green =digitalRead(12);
       Serial.print("Red");
       Serial.println(red); 
       Serial.print("Blue");
       Serial.println(blue);
       Serial.print("Green");
       Serial.println(green);  
  delay(1000);                       // wait for a second
  digitalWrite(12, HIGH);
            red = digitalRead(13);
             blue = digitalRead(8);
             green =digitalRead(12);
             Serial.print("Red");
             Serial.println(red); 
             Serial.print("Blue");
             Serial.println(blue);
             Serial.print("Green");
             Serial.println(green);       
  delay(1000);
  digitalWrite(12, LOW);
          red = digitalRead(13);
         blue = digitalRead(8);
         green =digitalRead(12);
         Serial.print("Red");
         Serial.println(red); 
         Serial.print("Blue");
         Serial.println(blue);
         Serial.print("Green");
         Serial.println(green); 
  delay(1000);                       // wait for a second
  digitalWrite(8, HIGH);
          red = digitalRead(13);
           blue = digitalRead(8);
           green =digitalRead(12);
           Serial.print("Red");
           Serial.println(red); 
           Serial.print("Blue");
           Serial.println(blue);
           Serial.print("Green");
           Serial.println(green);
  delay(1000);
  digitalWrite(8, LOW);
           red = digitalRead(13);
           blue = digitalRead(8);
           green =digitalRead(12);
           Serial.print("Red");
           Serial.println(red); 
           Serial.print("Blue");
           Serial.println(blue);
           Serial.print("Green");
           Serial.println(green);
  delay(1000);
  
}
