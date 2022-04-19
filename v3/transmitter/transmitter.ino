#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
byte pipe;
boolean state = 0;
int count2 = 0;
int count3 = 0;
int joyValue = 0;

byte h = 0, v = 0;         // variables used in for loops
const int period = 50;     // A little delay to avoid errors.
int kdelay = 0;            // Non Blocking Delay
const byte rows = 4;       // Rows in Keypad
const byte columns = 4;    // Columns in Keypad
const byte Output[rows] = {6}; //Row connceted to Arduino Pins
const byte Input[columns] = {2, 3, 4, 5}; //Columns connected to Arduino Pins

int state_btn = 1;

void setup() {
  for (byte i = 0; i < rows; i++) //Loop to declare output pins.
  {
    pinMode(Output[i], OUTPUT);
  }
  for (byte s = 0; s < columns; s++) // Loop to decalre Input pins, Initial Pulledup.
  {
    pinMode(Input[s], INPUT_PULLUP);
  }

  pinMode(8, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(5);
  radio.setDataRate     (RF24_250KBPS);
  radio.setPALevel      (RF24_PA_HIGH);
  radio.openWritingPipe (0xAABBCCDD11LL);
  radio.stopListening();
}
void loop() {
  delay(5);
  if (millis() - kdelay > period) //used to make non-blocking delay
  {
    kdelay = millis(); //capture time from millis function
    switch (keypad())     //Switch to get which button is pressed.
    {
      case 0:
        state_btn = 0;
        Serial.println(state_btn);

        if (radio.write(&state_btn, sizeof(state_btn))) digitalWrite(8, HIGH);
        else digitalWrite(8, LOW);

        break;

      case 1:
        state_btn = 1;
        Serial.println(state_btn);

        if (radio.write(&state_btn, sizeof(state_btn))) digitalWrite(8, HIGH);
        else digitalWrite(8, LOW);
        break;
      case 2:
        state_btn = 2;
        Serial.println(state_btn);

        if (radio.write(&state_btn, sizeof(state_btn))) digitalWrite(8, HIGH);
        else digitalWrite(8, LOW);
        break;
      case 3:
        state_btn = 3;
        Serial.println(state_btn);

        if (radio.write(&state_btn, sizeof(state_btn))) digitalWrite(8, HIGH);
        else digitalWrite(8, LOW);
        break;
      default:
        ;
    }
  }
}


// Below function is used to detect which button is pressed.

byte keypad()
{
  static bool no_press_flag = 0;
  for (byte x = 0; x < columns; x++)
  {
    if (digitalRead(Input[x]) == HIGH);
    else
      break;
    if (x == (columns - 1))
    {
      no_press_flag = 1;
      h = 0;
      v = 0;
    }
  }
  if (no_press_flag == 1)
  {
    for (byte r = 0; r < rows; r++)
      digitalWrite(Output[r], LOW);
    for (h = 0; h < columns; h++)
    {
      if (digitalRead(Input[h]) == HIGH)
        continue;
      else
      {
        for (v = 0; v < rows; v++)
        {
          digitalWrite(Output[v], HIGH);
          if (digitalRead(Input[h]) == HIGH)
          {
            no_press_flag = 0;
            for (byte w = 0; w < rows; w++)
              digitalWrite(Output[w], LOW);
            return v * 4 + h;
          }
        }
      }
    }
  }
  return 50;
}
