
int temp = 0;
char val;
void setup() 
{
  Serial.begin(9600);
   Serial.print("Waiting for Data....");

}
 
void loop()
{
  temp = analogRead(A0);
  if(Serial.available()>0){
    val = Serial.read();
    Serial.print("Print Temp Value ");
    Serial.print(temp);
    delay(1000);
  }
}
