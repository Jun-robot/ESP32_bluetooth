#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Controller");

  pinMode(2, OUTPUT);

  //デバイス名は"ESP32"としました。サンプルスケッチではESP32testとなっています。

  Serial.println("The device started, now you can pair it with bluetooth!");


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
