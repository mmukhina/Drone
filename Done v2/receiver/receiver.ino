#include <SPI.h>                            
#include <nRF24L01.h>
#include <RF24.h>  
#include <Servo.h>
#define button 4
RF24 radio(9, 10);     
Servo servo3;
byte pipe;
boolean state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(7, OUTPUT);
  delay(1000);
  radio.begin();                            
  radio.setChannel(5); 
  radio.setAutoAck(true);                     
  radio.setDataRate(RF24_250KBPS);     
  radio.setPALevel(RF24_PA_HIGH);
  radio.openReadingPipe(1, 0xAABBCCDD11LL);   
  radio.openWritingPipe(0xAABBCCDD22LL);
  radio.startListening();
  servo3.attach(5);
  pinMode(button, INPUT);
  digitalWrite(7, HIGH);
}

void loop () {
  delay(5);
  digitalWrite(7, HIGH);
//  if (radio.available(&pipe)){
//      digitalWrite(7, HIGH);
//      int angleValue = 0;
//      radio.read(&angleValue, sizeof(angleValue));
//      Serial.println(angleValue);
//    }
//  else digitalWrite(7, LOW);
  

//  state = digitalRead(button);
//  if (state == 1){
//    radio.stopListening();
//    delay(100);
//    radio.write(&state, sizeof(state));
//  }
//  radio.startListening();
}
