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
  delay(1000);
  radio.begin();                            
  radio.setChannel(5);                      
  radio.setDataRate(RF24_250KBPS);     
  radio.setPALevel(RF24_PA_HIGH);
  radio.openReadingPipe(1, 0xAABBCCDD11LL);  
  radio.openWritingPipe(0xAABBCCDD22LL);
  radio.startListening();
  servo3.attach(5);
  pinMode(button, INPUT);
}

void loop () {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    while (radio.available()) {
      int angleV = 0;
      radio.read(&angleV, sizeof(angleV));
      servo3.write(angleV);
    }
    delay(5);
    radio.stopListening();
    state = digitalRead(button);
    radio.write(&state, sizeof(state));
    Serial.println(state);
  }
  
}
