#define button 8
int val;

void setup() 
{
    Serial.begin(9600);
    pinMode(button, INPUT_PULLUP);
}
 
void loop()
{
 /* if(Serial.available()>0){
    Serial.write(Serial.read());  //No Debouce Condition
  }*/
  val = digitalRead(button);
  if(val == LOW){
    Serial.write(100);
   //Serial.println(val);
   delay(500);
 }
  
  delay(50);
}
