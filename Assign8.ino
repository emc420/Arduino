#define RED 3
#define GREEN 5
#define BLUE 6

#define buttonR 2
#define buttonG 4
#define buttonB 7
#define buttonO 10

const int clkPin = 12; //the clk attach to pin2
const int dtPin = 8; //the dt attach to pin3
const int swPin = 13 ; //the number of the button
int clk = 0;
int dt = 0;
char changeFlag = 'O';
int intensity=0;
char rotCntrl = 'A';

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonR, INPUT_PULLUP);
  pinMode(buttonG, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(buttonO, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  Serial.begin(9600); // initialize serial communications at 9600 bps

}

void loop() {

  if (digitalRead(buttonR) == LOW) {
    changeFlag = 'R';  
  }
  if (digitalRead(buttonG) == LOW) {
    changeFlag = 'G';

  }
  if (digitalRead(buttonB) == LOW) {

    changeFlag = 'B';

  }
  if (digitalRead(buttonO) == LOW) {
    changeFlag = 'O';
  }

      if(changeFlag=='R'){
       analogWrite(GREEN, 255);
      analogWrite(BLUE, 255);
      analogWrite(RED, intensity);
      rotCntrl = 'A';
      // delay(10);
    }else if(changeFlag=='G'){
       analogWrite(RED, 255);
      analogWrite(BLUE, 255);
      analogWrite(GREEN, intensity);
      rotCntrl = 'A';
      // delay(10);
    }else if(changeFlag=='B'){
       analogWrite(RED, 255);
      analogWrite(GREEN, 255);
      analogWrite(BLUE, intensity);
      rotCntrl = 'A';
     //  delay(10);
    }else{
      analogWrite(RED, 255);
     analogWrite(GREEN, 255);
     analogWrite(BLUE, 255);
     rotCntrl = 'N';
    }
  // put your main code here, to run repeatedly:
  int newCLK = digitalRead(clkPin);
  int newDT = digitalRead(dtPin);
  int Sw =  digitalRead(swPin);
    if(Sw == LOW){
      rotCntrl = 'N';
      //Serial.println("Sw is low");
    }else{
      rotCntrl = 'A';
      //Serial.println("Sw is high");
    }
    if ( (newCLK != clk) && newCLK == LOW ) { // CLK has changed from HIGH to LOW
      if ( dt == LOW) {
        //Serial.println("Clockwise");
        if(intensity<=255 && rotCntrl!='N'){
          intensity+=20;
        }
      } else {
        //Serial.println("Counter-Clockwise");
        if(intensity>0 && rotCntrl!='N'){
          intensity-=20;
        }
        
      }
  }
  clk = newCLK;
  dt = newDT;
  Serial.println(intensity);
  //Serial.println(rotCntrl);

  delay(10);
}
