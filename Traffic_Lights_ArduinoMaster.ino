
#define cntrl 2


void setup() {
  // put your setup code here, to run once:
  pinMode(cntrl, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(cntrl, LOW);

  delay(500);

  digitalWrite(cntrl, HIGH);

  delay(500);

}
