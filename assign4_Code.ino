int stateP = HIGH;
int stateC = HIGH;

void setup() {
  // put your setup code here, to run once:
    pinMode(2, OUTPUT);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.flush();
  digitalWrite(2, LOW);

}



void loop() {
  // put your main code here, to run repeatedly:
  stateP = stateC;
  while(stateP==stateC){
    stateC = digitalRead(8) & digitalRead(7);
  }

  if (stateC == LOW){
     if((digitalRead(2)) == LOW){
      digitalWrite(2, HIGH);
    }else{
       digitalWrite(2, LOW);
    }
  }

}
