#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Controller");

  pinMode(2, OUTPUT);


  Serial.println("you can pair it with bluetooth!");


  digitalWrite(2, HIGH);
}

int a;

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());

    //Serial.write(SerialBT.readStringUntil("#"));
  }

}
