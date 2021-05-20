#include <Wire.h>

#define RED 4
#define YELLOW 7
#define GREEN 8

char changeFlag = 'O';
byte inp = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(12);
  Wire.onReceive(receiveEvent);
  delay(50);
  Wire.onRequest(requestEvent);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);

}

void receiveEvent(int x) {
  while(Wire.available()){
    inp = Wire.read();
    //Serial.print(inp);
    switch(inp) {
        case 0:
          changeFlag = 'O';
          break;
        case 4:
          changeFlag = 'R';
          break;
        case 5:
          changeFlag = 'B';
          break;
        case 8:
          changeFlag = 'G';
          break;
        case 7:
          changeFlag = 'Y';
          break;
        default:
          changeFlag = 'O';
          break;
       }
      delay(300);
     
  }
  if(changeFlag=='R'){
       digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(RED, HIGH);
      // delay(10);
    }else if(changeFlag=='G'){
       digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);
      // delay(10);
    }else if(changeFlag=='Y'){
       digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH);
     //  delay(10);
    }else if(changeFlag=='B'){
       digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH);
     //  delay(10);
    }else{
      digitalWrite(RED, LOW);
     digitalWrite(GREEN, LOW);
     digitalWrite(YELLOW, LOW);
    }
  delay(100);
}
void requestEvent(){
  if(inp == 0){
    Wire.write("S2 Lights r Off");
  }else if(inp==4){
    Wire.write("S2 R is On");
  }else if(inp == 5){
    Wire.write("S2 R & Y are On");
  }else if(inp == 7){
    Wire.write("S2 Y is On");
  }else if(inp == 8){
     Wire.write("S2 G is On");
  }
}
