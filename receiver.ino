#include <LiquidCrystal.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
int msg[2];
int bilgi[1]; 
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int buzzer = 8;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup(void){
 Serial.begin(9600);
 radio.begin();
 lcd.begin(16, 2);
 lcd.setCursor(0,1);
 radio.openReadingPipe(1,pipe);
 radio.startListening();
 pinMode(buzzer, OUTPUT);
}

void loop(void){
 lcd.setCursor(0,0);
 lcd.print("adasdsa");
 lcd.display();
 if (radio.available()){
   bool done = false;
   bool done2 = false;    
   while (!done && !done2){
     done = radio.read(msg, 1);
     done2 = radio.read(bilgi, 1);
     if (bilgi[0] == 1){
      delay(10);
      digitalWrite(buzzer, 500);
      Serial.print("Sıcaklık : ");
      Serial.println(msg[0]);
      Serial.println("SERKAN AYAN - ODA 1");
     }else if(bilgi[0] == 2){  
      delay(10);
      digitalWrite(buzzer, 500);
      Serial.print("Sıcaklık : ");
      Serial.println(msg[0]);
      Serial.println("ONUR KAÇMAZ - ODA 2");
     }else if(bilgi[0] == 3){
      delay(10);
      digitalWrite(buzzer, 500);
      Serial.print("Sıcaklık : ");
      Serial.println(msg[0]);
      Serial.println("EMRE SÖYLER - ODA 3");
     }else if(bilgi[0] == 4){
      delay(10);
      digitalWrite(buzzer, 500);
      Serial.print("Sıcaklık : ");
      Serial.println(msg[0]);
      Serial.println("MEHMETCAN SOHTA - ODA 4"); 
     }else {
      digitalWrite(buzzer, LOW);
     }
     delay(10);
   }
 }
}
