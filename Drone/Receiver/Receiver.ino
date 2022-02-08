
#include <Servo.h> 
#define LED 13
 
Servo motor1; 
Servo motor2;
Servo motor3;
Servo motor4;
 
int potpin = 0; 
int val;        
int count = 0;
 
void setup() 
{ 
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  
  motor1.attach(9); 
  motor2.attach(10);
  motor3.attach(11);
  motor4.attach(12);
  delay(2000);
  motor1.write(179);
  motor2.write(179);
  motor3.write(179);
  motor4.write(179);
  delay(8000);
  motor1.write(0);
  motor2.write(0);
  motor3.write(0);
  motor4.write(0);
  delay(8000);

  digitalWrite(LED, HIGH);
} 
 
void loop() {
   
  if (Serial.read() == '1' and count == 0){
    for (int i = 0; i <= 80; i++){
      motor1.write(i);
      motor2.write(i);
      motor3.write(i);
      motor4.write(i);
      delay(15);
      Serial.print(i);
      Serial.print("\n");
      }
    count = 1;
  }

  if (Serial.read() == '2' and count == 1{
    for (int i = 80; i <= 0; i--){
    motor1.write(i);
    motor2.write(i);
    motor3.write(i);
    motor4.write(i);
    delay(15);
    Serial.print(i);
    Serial.print("\n");
    }
    count = 0;
   }
    
}
