
#include <Servo.h> 
 
Servo motor1;  // create servo object to control a servo 
Servo motor2;
Servo motor3;
Servo motor4;
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
char data;
 
void setup() 
{ 
  motor1.attach(9);  // attaches the servo on pin 9 to the servo object 
  motor2.attach(10);
  motor3.attach(11);
  motor4.attach(12);
  Serial.begin(9600);
  motor1.write(30);
} 
 
void loop() 
{ 
        // scale it to use it with the servo (value between 0 and 180) 
    data = Serial.read();
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
    val = map(val, 0, 1023, 0, 179); 
    //if (data == 'a'){
      motor1.write(val);
      Serial.print("done1\n");// sets the servo position according to the scaled value 
      delay(15); 
    //}
    
   
  
  // motor2.write(val);
  //motor3.write(val);
  //motor4.write(val);
                            // waits for the servo to get there 
}
