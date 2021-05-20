#define RED 8
#define GREEN 2
#define BLUE 7

   int topThres = 0;
   int bottomThres = 0;

void setup() {
  // put your setup code here, to run once:
   pinMode(RED, OUTPUT);
   pinMode(GREEN, OUTPUT);
   pinMode(BLUE, OUTPUT);

   Serial.begin(9600);
   

}

void loop() {
  // put your main code here, to run repeatedly:
    char button=' ';
  int b=analogRead(A1);
  int value = analogRead(A0);

  
  if (b > 1000){
    button=' ';
  } else if (b < 100){
    button='t';
    topThres = value;
  } else if ( (b >450) && (b<550) ){
    button='b';
    bottomThres = value;
  }

  if (value<bottomThres){
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }else if (value>bottomThres & value<topThres){
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
  }else if(value>topThres){
    digitalWrite(GREEN, HIGH);
     digitalWrite(BLUE, LOW);
    digitalWrite(RED, LOW);
  }
  Serial.print("Top Threshold: ");
  Serial.println(topThres);
  Serial.print("Bottom Threshold: ");
  Serial.println(bottomThres);
  
  
//  Serial.println(analogRead(A0));
 //  delay (1000);
}
