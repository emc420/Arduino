/*at+inqm=0,2,48 ,
 * at+pair= Slave1
 * at+link = Slave2
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write('a'); 
  Serial.write('y');                          

  delay(2000);

  Serial.write('b'); 
  Serial.write('z');   

  delay(2000);

  Serial.write('c'); 
  Serial.write('w');

  delay(2000);

  Serial.write('d'); 
  Serial.write('x');

  delay(2000);
}
