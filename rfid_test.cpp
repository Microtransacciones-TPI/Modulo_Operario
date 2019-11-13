//#include <Arduino.h> --> Solo aplica para platform.io
#include <SPI.h>
#include "MFRC522.h"
#include <Wire.h>


#define RST_PIN 22
#define SS_PIN 5

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
while (!Serial);
SPI.begin();
mfrc522.PCD_Init();
mfrc522.PCD_DumpVersionToSerial();


}

void loop() {
  // put your main code here, to run repeatedly:

// Look for new cards
if ( ! mfrc522.PICC_IsNewCardPresent()) {
return;
}

// Select one of the cards
if ( ! mfrc522.PICC_ReadCardSerial()) {
return;
}

// Dump debug info about the card; PICC_HaltA() is automatically called
//mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

//** Imprime en pantalla el UID
rfidUidPrintHex();

}

void rfidUidPrintHex()
{
	//Serial.print("Card UID: (HEX)");
	
	for(byte i = 0; i < mfrc522.uid.size; i++)
	{
//		Serial.print(mfrc522.uid.uidByte[i], HEX);	// print without spaces
		
		Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
		Serial.print(mfrc522.uid.uidByte[i], HEX);
	}
	
	Serial.println();
}


