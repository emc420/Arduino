/*
* Bluetooh Basic: LED ON OFF - Avishkar
* Coder - Mayoogh Girish
* Website - http://bit.do/Avishkar
* Download the App : https://github.com/Mayoogh/Arduino-Bluetooth-Basic
* This program lets you to control a LED on pin 13 of arduino using a bluetooth module
*/
char data = 0;            //Variable for storing received data
#define LedR 12
int delayPeriod = 0;
void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
    pinMode(LedR, OUTPUT);
}
void loop()
{
  
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      if(data == '0'){              // Checks whether value of data is equal to 1
        // digitalWrite(13, HIGH);   //If value is 1 then LED turns ON
         delayPeriod = 100;
      }
      else if(data == '1'){         //  Checks whether value of data is equal to 0
       //  digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
         delayPeriod = 200;
      }
       else if(data == '2'){         //  Checks whether value of data is equal to 0
       //  digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
         delayPeriod = 400;
      }
       else if(data == '3'){         //  Checks whether value of data is equal to 0
       //  digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
         delayPeriod = 600;
      }
       else if(data == '4'){         //  Checks whether value of data is equal to 0
       //  digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
         delayPeriod = 800;
      }
       else if(data == '5'){         //  Checks whether value of data is equal to 0
       //  digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
         delayPeriod = 1000;
      }
       else if(data == '6'){         //  Checks whether value of data is equal to 0
       //  digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
         delayPeriod = 1200;
      }
       else if(data == '7'){         //  Checks whether value of data is equal to 0
       //  digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
         delayPeriod = 1400;
      }
      else if(data == '8'){         //  Checks whether value of data is equal to 0
       //  digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
         delayPeriod = 1600;
      }
      else if(data == '9'){         //  Checks whether value of data is equal to 0
       //  digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
         delayPeriod = 1800;
      }else{
        delayPeriod = 0;
      }
   }
  digitalWrite(LedR, HIGH);
  delay(delayPeriod);
  digitalWrite(LedR, LOW);
  delay(delayPeriod);
}
