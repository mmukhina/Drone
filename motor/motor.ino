
#include <Servo.h> 
 
Servo motor1;  // create servo object to control a servo 
Servo motor2;
Servo motor3;
Servo motor4;
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
int count = 0;
 
void setup() 
{ 
  motor1.attach(9);  // attaches the servo on pin 9 to the servo object 
  motor2.attach(10);
  motor3.attach(11);
  motor4.attach(12);
  Serial.begin(9600);
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
  motor1.write(80);
  delay(500);
  motor2.write(80);
  delay(500);
  motor3.write(80);
  delay(500);
  motor4.write(80);
  delay(500);
} 
 
void loop() 
{ 
  motor1.write(80);
  motor2.write(80);
  motor3.write(80);
  motor4.write(80);
  //delay(100);
  //val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  //val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  //Serial.print(val);
  //Serial.print("\n");
  //motor1.write(0); 
  //delay(15); 
  //motor1.write(85);                   // sets the servo position according to the scaled value 
  //motor2.write(val);
  //motor3.write(val);
  //motor4.write(val);
  //delay(15);                           // waits for the servo to get there 
//  if (count == 0){
//    for (int i = 0; i <= 90; i++) {
//    Serial.print(i);
//    Serial.print("\n");
//    motor1.write(i);
//    //delay(10);
//    }
//    count = 1;
//  }
//  //writemicrosecond

  //mot
}
