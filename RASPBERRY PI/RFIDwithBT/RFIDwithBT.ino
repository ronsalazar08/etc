
#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h> //Serial library

SoftwareSerial bt (5,6);  //RX, TX (Switched on the Bluetooth - RX -> TX | TX -> RX)
constexpr uint8_t RST_PIN = 9;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = 10;     // Configurable, see typical pin layout above
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];
String code="";
void setup() { 
  //Serial.setTimeout(100);//for readstring
  Serial.begin(9600);
  bt.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
}
 
void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  if ( ! rfid.PICC_ReadCardSerial())
    return;

    printHex(rfid.uid.uidByte, rfid.uid.size);
    //Serial.println();
  rfid.PICC_HaltA();
  bt.println(code);
  code ="";
}


/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? "0" : "");
    if(buffer[i] < 0x10){
      code.concat("0");
    }
    Serial.println(buffer[i], HEX);
    String s = String(buffer[i], HEX);
    code.concat(s);
  }
  
}
