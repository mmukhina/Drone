#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define button 4
RF24 radio(9, 10);
Servo servo3;
byte pipe;
boolean state = 0;
int angleValue = 5;
int count = 0;

#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

int potpin = 0;
int val;


void setup() {
  Serial.begin(9600);
  //pinMode(14, OUTPUT);
  //pinMode(15, OUTPUT);
  pinMode(7, OUTPUT);
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

  motor1.attach(A1);
  motor2.attach(A2);
  motor3.attach(A3);
  motor4.attach(A0);
  motor1.write(179);
  motor2.write(179);
  motor3.write(179);
  motor4.write(179);
  delay(8000);
  motor1.write(0);
  motor2.write(0);
  motor3.write(0);
  motor4.write(0);
  digitalWrite(7, HIGH);
  delay(8000);
  digitalWrite(7, LOW);

}

void loop () {
  delay(5);
  if (radio.available(&pipe)) {
    digitalWrite(7, HIGH);

    radio.read(&angleValue, sizeof(angleValue));
    Serial.println(angleValue);


  }
  else digitalWrite(7, LOW);


  if (angleValue == 0) {



  }
  else if (angleValue == 1) {
    if (count == 0) {
      for (int i = 0; i <= 90; i++) {
        motor1.write(i);
        motor2.write(i);
        motor3.write(i);
        motor4.write(i);
        delay(30);
        Serial.print(i);
        Serial.print("\n");
      }
      count = 1;
    }

  }

  else if (angleValue == 2) {
    if (count == 1) {
      for (int i = 90; i >= 0; i--) {
        motor1.write(i);
        motor2.write(i);
        motor3.write(i);
        motor4.write(i);
        delay(30);
        Serial.print(i);
        Serial.print("\n");
      }
      count = 0;
    }
  }


  //  state = digitalRead(button);
  //  if (state == 1){
  //    radio.stopListening();
  //    delay(100);
  //    radio.write(&state, sizeof(state));
  //  }
  //  radio.startListening();
}
