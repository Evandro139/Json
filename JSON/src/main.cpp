//Serial.begin(9600);

   //ENVIO DE DADOS//
  //float umidade = 60.3;
  //float tempC = 20.5;
  //float tempF = 33.7;

  //JsonDocument doc;

//doc["umidade"] = umidade;
//doc["tempC"] = tempC;
//doc["tempF"] = tempF;

//String JsonString;
///serializeJson(doc, JsonString);

//Serial.println("JSON gerado:  ");
//Serial.println(JsonString);
/*
String mensagemRecebida = "{\"umidade\":60.3, \"tempC\":20.5, \"tempF\":33.7}";

JsonDocument doc;

DeserializationError erro = deserializeJson(doc, mensagemRecebida);

if(erro)
{
  Serial.print("Erro ao interpretar JSON:");
  Serial.println(erro.c_str());
  return;
}

float umidade = doc["umidade "];
float tempC = doc["tempC "];
float tempF = doc["tempF "];

Serial.println("JSON interpretado com sucesso!");
Serial.print("Umidade: "); Serial.println(umidade);
Serial.print("temp (C): ");Serial.println(tempC);
Serial.print("temp (f): ");Serial.println(tempF);

}
*/

#include <Arduino.h>
#include <ArduinoJson.h>
#include <BluetoothSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

BluetoothSerial BT;
LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup() {
  Serial.begin(9600);

  if (BT.begin("EspSamuelEvan", false)) {
    Serial.print("Endereço Bluetooth: ");
    Serial.println(BT.getBtAddressString());
  } else {
    Serial.println("Erro ao iniciar Bluetooth!");
    while (true);
  }

  lcd.init();
  delay(100);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Aguardando dados...");
}

void loop() {
  if (BT.available()) {
    String mensagemRecebida = BT.readString();
    Serial.println("Recebido: " + mensagemRecebida);

    JsonDocument doc;
    DeserializationError erro = deserializeJson(doc, mensagemRecebida);
    if (erro) {
      Serial.print("Erro ao ler JSON: ");
      Serial.println(erro.f_str());
      return;
    }

    float temperaturaC = doc["temperaturaC"];
    float umidade = doc["umidade"];
    float fahrenheit = doc["fahrenheit"];

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperaturaC);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print(fahrenheit);
    lcd.print("F");
    lcd.setCursor(0, 2);
    lcd.print("Umid: ");
    lcd.print(umidade);
    lcd.print("%");
  }
}
