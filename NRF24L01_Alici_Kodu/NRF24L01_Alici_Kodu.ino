#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(5, 6);   // nRF24L01 (CE, CSN)

const byte address[6] = "00002";

void setup() {
  Serial.begin(9600);

  boolean radio_init = radio.begin();
  
  if(radio_init == false)
    Serial.println("NRF24L01 Init Failed!");
  else
    Serial.println("NRF24L01 Init Succesful :)");

  radio.setAutoAck(false);  //radio.write() bilgisi AutoAck false olduğu için alınamaz!
  radio.setChannel(115);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS); 
  radio.openReadingPipe(1, address);
  radio.startListening();

  Serial.println("Configurations Succesful :)");

}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println("Gelen Mesaj: " + String(text));
  }

}
