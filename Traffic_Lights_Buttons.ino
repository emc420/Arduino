#define RED 4
#define YELLOW 7
#define GREEN 8
#define button 2

char changeFlag = 'O';

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(button, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button)== LOW){
    switch(changeFlag) {
        case 'O':
          changeFlag = 'R';
          break;
        case 'R':
          changeFlag = 'B';
          break;
        case 'B':
          changeFlag = 'G';
          break;
        case 'Y':
            changeFlag = 'R';        
          break;
        case 'G':
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

}
