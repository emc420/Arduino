#define RED 6
#define GREEN 5
#define BLUE 3
#define delayTime 10 

// Connection of the switches (which will "pull to GND")
const int RedSwitchPin = 12;
const int GreenSwitchPin = 8;
const int BlueSwitchPin = 7;
const int OffSwitchPin = 4;

int intensity;
int flagInDc;
char changeFlag;
//int redVal;
//int blueVal;
//int greenVal;

void setup() {
  // put your setup code here, to run once:
     pinMode(RED, OUTPUT);
     pinMode(GREEN, OUTPUT);
     pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
     digitalWrite(GREEN, HIGH);
     digitalWrite(BLUE, HIGH);
     Serial.begin(9600);
     Serial.flush();
     pinMode(RedSwitchPin, INPUT_PULLUP);
     pinMode(GreenSwitchPin, INPUT_PULLUP);
     pinMode(BlueSwitchPin, INPUT_PULLUP);
     pinMode(OffSwitchPin, INPUT_PULLUP);
     intensity=0;
     changeFlag = 'O';
     flagInDc=1;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(RedSwitchPin) == LOW) {
    changeFlag = 'R';  
  }
  if (digitalRead(GreenSwitchPin) == LOW) {
    changeFlag = 'G';

  }
  if (digitalRead(BlueSwitchPin) == LOW) {

    changeFlag = 'B';

  }
  if (digitalRead(OffSwitchPin) == LOW) {
    changeFlag = 'O';
  }

    if(changeFlag=='R'){
       analogWrite(GREEN, 255);
      analogWrite(BLUE, 255);
      analogWrite(RED, intensity);
      // delay(10);
    }else if(changeFlag=='G'){
       analogWrite(RED, 255);
      analogWrite(BLUE, 255);
      analogWrite(GREEN, intensity);
      // delay(10);
    }else if(changeFlag=='B'){
       analogWrite(RED, 255);
      analogWrite(GREEN, 255);
      analogWrite(BLUE, intensity);
     //  delay(10);
    }else{
      analogWrite(RED, 255);
     analogWrite(GREEN, 255);
     analogWrite(BLUE, 255);
    
   
  }
  
  if(intensity==255){
    flagInDc = 0;
  }
  if(intensity == 0){
    flagInDc =1;
  }
  if(flagInDc == 0){
    intensity = intensity-1;
  }else{
    intensity = intensity+1;
  }
  delay(10);
  

}
