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
#define RED 9
#define GREEN 11
#define BLUE 10
#define delayTime 10 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED, OUTPUT);
 pinMode(GREEN, OUTPUT);
 pinMode(BLUE, OUTPUT);
 digitalWrite(RED, HIGH);
 digitalWrite(GREEN, HIGH);
 digitalWrite(BLUE, HIGH);
 Serial.begin(9600);
 Serial.flush();
  
}

// define variables
int redValue;
int greenValue;
int blueValue;

// the loop function runs over and over again forever
void loop() {
    Serial.println("Working...");
     redValue = 255; // choose a value between 1 and 255 to change the color.
     greenValue = 0;
     blueValue = 0;
     analogWrite(RED, redValue);
     analogWrite(GREEN, greenValue);
     analogWrite(BLUE, blueValue);
     delay(1000);
     Serial.println(redValue);
     for (int i = 0; i < 255; i += 1){ // fades out red bring green full when i=255
      redValue -= 1;
      greenValue += 1;
      if (blueValue<50){
         blueValue += 1;
      }
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, greenValue);
      delay(delayTime);
     }
 
}
