#include <Adafruit_Fingerprint.h>

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);



void setup()  
{
  
  Serial.begin(9600);
  while (!Serial);  
  delay(100);

  Serial.println("DELETING ALL TRACE #");
  Serial.println("Press 'Y' key to continue");

  while (1) {
    if (Serial.available() && (Serial.read() == 'Y')) {
      
      break;
      
    }
  }

  finger.begin(57600);
   
  finger.emptyDatabase();

  Serial.println("\n\n\n\n********          ALL TRACE # WAS DELETED          ************** ");
  Serial.println("********   PLEASE CLOSE THE SERIAL MONITOR WINDOW  ************** ");
}

void loop() {
}

