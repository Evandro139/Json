#include <Arduino.h>
#include <ArduinoJson.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;

int gasPin = 34;

unsigned long ultimoEnvio = 0;
const unsigned long intervalo = 1500;

void setup() {
  Serial.begin(9600);
  Serial.println("Sensor MQ-5 iniciado...");

  if (BT.begin("EspSlaveSamuel", false)) {
    Serial.print("Endereço Bluetooth: ");
    Serial.println(BT.getBtAddressString());
  } else {
    Serial.println("Erro ao iniciar Bluetooth!");
    while (true);
  }
}

void loop() {
  if (millis() - ultimoEnvio >= intervalo) {
    ultimoEnvio = millis();

    int valor = analogRead(gasPin);
    Serial.print("Leitura MQ-5: ");
    Serial.println(valor);

    int valorRemap = map(valor, 0, 4095, 0, 180);

    JsonDocument doc;
    doc["valor"] = valorRemap;

    String jsonString;
    serializeJson(doc, jsonString);

    Serial.print("JSON enviado: ");
    Serial.println(jsonString);

    BT.println(jsonString);
  }
}
