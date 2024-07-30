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
  radio.openWritingPipe(address);
  radio.stopListening();

  Serial.println("Configurations Succesful :)");
}

void loop() {
  const char text[] = "Hello World"; // 11byte uzunluğu
  radio.write(&text, sizeof(text)); //write veri göndermek için kullanılır! write(verininAdresi, verininBoyutu);
  Serial.println("Mesaj Gonderildi :)");
  delay(1000);

}
