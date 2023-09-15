#include <SoftwareSerial.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup()
{
mySoftwareSerial.begin(9600);
Serial.begin(9600);
Serial.println();
Serial.println(F("DFRobot DFPlayer Mini Demo"));
Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
 
if (!myDFPlayer.begin(mySoftwareSerial)) //Use softwareSerial to communicate with mp3.
  { 
  Serial.println(F("Unable to begin:"));
  Serial.println(F("1.Please recheck the connection!"));
  Serial.println(F("2.Please insert the SD card!"));
  while (true) 
    {
    delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
Serial.println(F("DFPlayer Mini online."));
myDFPlayer.volume(20); //ตั้งระดับความดังของเสียง 0-30
mySerial.begin(9600);
Serial.println("Initializing..."); 
delay(1000);
mySerial.println("AT"); //Once the handshake test is successful, i t will back to OK
updateSerial();
mySerial.println("ATD+ +66885939942;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
updateSerial();

}

void loop()
{
// call function
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}

void voice()
{
  myDFPlayer.play(13);
  myDFPlayer.play(12);
}
