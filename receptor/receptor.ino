#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define rf_ce 9
#define rf_cs 10

RF24 radio(rf_ce,rf_cs);

byte data[2];
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(){
  Serial.begin(9600);
  Serial.println("Reading sensors data...");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}

void loop() {
  if (radio.available()){
   bool done = false;    
   while (!done){
     done = radio.read(data, sizeof(data));      
     Serial.println(data[0]);
     Serial.println(data[1]);
   }
  } else{
    Serial.println("No radio available");
  }
}
