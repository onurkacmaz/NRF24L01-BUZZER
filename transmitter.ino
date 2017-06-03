#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
int msg[1];
int bilgi[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 7;
int SW2 = 6;
int SW3 = 5;
int SW4 = 4;

void setup(void){
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(pipe);
}

void loop(void){

  int a = analogRead(A0);
  a = a+13;
  
 if (digitalRead(SW1) == HIGH){
   msg[0] = a;
   bilgi[0] = 1;
   radio.write(msg, 1);
   radio.write(bilgi, 1);
   Serial.println(a);
 }
 if(digitalRead(SW2) == HIGH) {
   msg[0] = a;
   bilgi[0] = 2;
   radio.write(msg, 1);
   radio.write(bilgi, 1);
   Serial.println(a);
 }
 if(digitalRead(SW3) == HIGH) {
   msg[0] = a;
   bilgi[0] = 3;
   radio.write(msg, 1);
   radio.write(bilgi, 1);
   Serial.println(a);
 }
 if(digitalRead(SW4) == HIGH) {
   msg[0] = a;
   bilgi[0] = 4;
   radio.write(msg, 1);
   radio.write(bilgi, 1);
   Serial.println(a);
 }
}
