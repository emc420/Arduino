#define RED 4
#define YELLOW 7
#define GREEN 8

char data = 0;            //Variable for storing received data
char changeFlag = 'm';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
     if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      switch(data) {
        case 'm':
          changeFlag = 'O';
          break;
        case 'w':
          changeFlag = 'R';
          break;
        case 'x':
          changeFlag = 'B';
          break;
        case 'y':
          changeFlag = 'G';
          break;
        case 'z':
          changeFlag = 'Y';
          break;
        default:
          //do nothing
          break;
       }
      delay(300);      
         if(changeFlag=='R'){
       digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(RED, HIGH);
      Serial.print("Slave 2 RED is high");
      // delay(10);
    }else if(changeFlag=='G'){
       digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);
      Serial.print("Slave 2 GREEN is high");
      // delay(10);
    }else if(changeFlag=='Y'){
       digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH);
      Serial.print("Slave 2 YELLOW is high");
     //  delay(10);
    }else if(changeFlag=='B'){
       digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH);
      Serial.print("Slave 2 RED & YELLOW are high");
     //  delay(10);
    }else{
      digitalWrite(RED, LOW);
     digitalWrite(GREEN, LOW);
     digitalWrite(YELLOW, LOW);
     Serial.print("Slave 2 if Off");
    }
  delay(100);

   }

}
