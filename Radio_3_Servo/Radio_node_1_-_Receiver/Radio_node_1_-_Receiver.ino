#include <SPI.h>                             
#include <nRF24L01.h>                        
#include <RF24.h>         

RF24 radio(9, 10);              
byte pipe;                               
boolean state = 0;  
int count2 = 0;
int count3 = 0;
int joyValue = 0;
  

void setup() {
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  radio.begin();                             
  radio.setChannel(5);                       
  radio.setDataRate     (RF24_250KBPS);      
  radio.setPALevel      (RF24_PA_HIGH);      
  radio.openWritingPipe (0xAABBCCDD11LL); 
  radio.stopListening();
  //radio.openReadingPipe (2, 0xAABBCCDD22LL);
  //radio.openReadingPipe (3, 0xAABBCCDD33LL);
  //radio.openWritingPipe (0xAABBCCDD22LL);                
  //  radio.stopListening   ();              
  //pinMode(12, OUTPUT);
  //radio.startListening();
}
void loop() {
  //radio.stopListening();
  delay(2000);
  //int joyValue = analogRead(14);
  int angleValue = 1;
  Serial.println(angleValue);
  if (radio.write(&angleValue, sizeof(angleValue))){
    digitalWrite(7, HIGH);
  }
  else digitalWrite(7, LOW);
}
//  radio.startListening();
//  delay(100);
//  if (radio.available(&pipe)){
//    digitalWrite(14, HIGH);
//  }
//  else digitalWrite(14, LOW);
//  radio.stopListening();
//  delay(100);
//}
//  delay(5);
//
//  radio.stopListening();
//  int potValue = analogRead(A0);
//  int angleValue = map(potValue, 0, 1023, 0, 180);
//  radio.write(&angleValue, sizeof(angleValue));
//
//  delay(5);
//  radio.startListening();
//  while (!radio.available());
//  radio.read(&state, sizeof(state));
//  if (state == HIGH) {
//    digitalWrite(14, HIGH);
//  }
//  else {
//    digitalWrite(14, LOW);
//  }
//}
  
    //if (pipe == 3){
    //  if (state == HIGH){
    //    if (count3 == 0){
    //      digitalWrite(14, HIGH);
    //      count3 = 1;
    //    }
    //    else{
//          digitalWrite(14, LOW);
 //         count3 = 0;
//        }
 //     }
 //   }
  
  //}
