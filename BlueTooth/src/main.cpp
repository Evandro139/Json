//-------------------------- BLUETOOTH SLAVE -----------------------------------
//BLUTOOTH SLAVE
// #include <Arduino.h>
// #include <BluetoothSerial.h>

// BluetoothSerial BT; 

// void setup() {
//   Serial.begin(9600);
//   Serial.setTimeout(5000);

// if(BT.begin("EspSlaveEvandro")){
//   Serial.println("Blutooth iniciado com sucesso");
//   Serial.print("Endereço blutooth ESP: ");
//   Serial.println(BT.getBtAddressString());

// }else{
//   Serial.println("Erro ao iniciar o blutooth");
// }


// }

// void loop() {
//   if(BT.available())
//   {
//     String mensagemRecebida = BT.readStringUntil('\n');
//     mensagemRecebida.trim();
//     Serial.printf("Mensagem recebida: %s", mensagemRecebida);
//   }

//   if(Serial.available())
//   {
//     String mensagemEnviar = Serial.readStringUntil('\n');
//     mensagemEnviar.trim();
//     BT.println(mensagemEnviar);
//   }
// }

//-------------------------- BLUETOOTH MASTER -----------------------------------
#include <Arduino.h>
#include <BluetoothSerial.h>

#define LED 2

BluetoothSerial BT;
bool piscando = false;
unsigned long tempoPiscaAnterior = 0;
bool estadoPisca = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  if (BT.begin("EspSlaveGusta", false)) {
    Serial.println("Bluetooth iniciado (SLAVE)");
    Serial.print("Endereço Bluetooth: ");
    Serial.println(BT.getBtAddressString());
  } else {
    Serial.println("Erro ao iniciar Bluetooth!");
    while (true);
  }
}

void loop() {
  if (BT.available()) {
    String comando = BT.readString();
    comando.trim();
    comando.toUpperCase();

    Serial.print("Comando recebido: ");
    Serial.println(comando);

    if (comando.endsWith("LEDON")) {
      piscando = false;
      digitalWrite(LED, HIGH);
      Serial.println("LED ligado");
      BT.println("OK LEDON");
    } 
    else if (comando.endsWith("LEDOFF")) {
      piscando = false;
      digitalWrite(LED, LOW);
      Serial.println("LED desligado");
      BT.println("OK LEDOFF");
    } 
    else if (comando.endsWith("AR")) {
      piscando = true;
      Serial.println("LED piscando");
      BT.println("OK AR");
    } 
    else {
      Serial.println("Comando desconhecido");
      BT.println("ERRO CMD");
    }
  }

  if (piscando) {
    unsigned long tempoAtual = millis();
    if (tempoAtual - tempoPiscaAnterior >= 500) {
      tempoPiscaAnterior = tempoAtual;
      estadoPisca = !estadoPisca;
      digitalWrite(LED, estadoPisca);
    }
  }
}