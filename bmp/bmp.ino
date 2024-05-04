#include <GyverBME280.h>
GyverBME280 bme;

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  
  // запуск датчика и проверка на работоспособность
  if (!bme.begin(0x76)) Serial.println("Error!");
}

void loop() {
  // температура
  // давление
  float pressure = bme.readPressure();
  Serial.print(pressureToAltitude(pressure)); // Выводим высоту в [м над ур. моря]

  Serial.println();
  delay(1000);
}
