#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define rf_ce 9
#define rf_cs 10

RF24 radio(rf_ce,rf_cs);

byte data[2];
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(){
  data[0] = 22;
  data[1] = 20;
  Serial.begin(9600);
  Serial.println("Reading sensors data...");
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop(){
  radio.write(data, sizeof(data));
}
