#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <BluetoothSerial.h>
//#include <ArduinoJson.h>

LiquidCrystal_I2C lcd(0x27, 16, 4); 
BluetoothSerial BT;

void setup() {
 
 lcd.init();                   
 lcd.backlight();
 Serial.begin(9600);

 
 
 
  //if (BT.begin("EspSamuelEvan", false)) {
     //Serial.print("Endereço Bluetooth: ");
     Serial.println(BT.getBtAddressString());
   //} else {
  //   Serial.println("Erro ao iniciar Bluetooth!");
  //   while (true);
  // }

  // lcd.setCursor(0, 0);
  // lcd.print("Aguardando dados");
}

void loop() {
  // if (BT.available()) {
  //   String mensagem = BT.readString();
  //   Serial.println(mensagem);
    
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   lcd.print("Recebido:");
  //   lcd.setCursor(0, 1);
  //   lcd.print(mensagem);
  // }

  //delay(500);
}