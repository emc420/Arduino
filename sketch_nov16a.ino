#define trigPin 12
#define echoPin 11
#define buzzer 8
#define RED 2
#define GREEN 4
#define BLUE 5
#define YELLOW 3
# define button 6

  int duration = 0;
  int distance = 0;
  boolean stopBuzz = false;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(trigPin, LOW);
   delayMicroseconds(1);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH, 5000000);
   distance = (duration / 2) / 29.1;
   Serial.print("Distance: ");
    Serial.println(distance);

   if(distance>0 & distance<=10){
          digitalWrite(RED, HIGH);
          digitalWrite(GREEN, LOW);
          digitalWrite(BLUE, LOW);
          digitalWrite(YELLOW, LOW);
          if(stopBuzz == false){
             tone(buzzer, 3000, 500);
             delay(1000);
          }
         
   }else if(distance>10 & distance<=30){
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(BLUE, LOW);
          digitalWrite(YELLOW, HIGH);
   }else if(distance>30 & distance<=60){
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, HIGH);
          digitalWrite(BLUE, LOW);
          digitalWrite(YELLOW, LOW);
   }else if(distance>60){
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(BLUE, HIGH);
          digitalWrite(YELLOW, LOW);
   }

   if(digitalRead(button)== LOW){
        Serial.print("Inside If staement: ");
        noTone(buzzer);
        stopBuzz = true;
        delay(3000);
        
   }else{
        stopBuzz = false;
   }

    Serial.print("Stop Buzzer: ");
    Serial.println(stopBuzz);


}
