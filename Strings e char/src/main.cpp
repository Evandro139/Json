#include <Arduino.h>

//char - mais recomendado para uso profissional 
//String - mais facil

char palavra[] = {'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};
char palavra1[] = "ON";
String palavra3 = "OFF";

void setup() {
  Serial.begin(9600);
  Serial.println();


  //----------- FUNCOES PARA CHAR --------------
// strcpy(palavra1, "SENAI");//substitui o valor anterior
//Serial.println(palavra2);

// Serial.print(strcmp(palavra2, "SENAI"));//se for igual retorna 0 
// if (strcmp(palavra2, "SENAI") == 0)
// {
//   Serial.print("são iguais");
// }else
// {
// Serial.print("são diferentes")

// }

// Serial.println(strncmp(palavra2, "senai", 5)); //compra a quantidade de caracteres 

// if(!strncmp(palavra2, "SENAI", 5))
// {
// Serial.println("Quantidade de caracteres iguais");
// }

//strstr(); //procura dentro da string pela primeira ocorrencia de uma substring

// if(strstr(palavra2, "NAI"))
// {
// Serial.println("palavra encontrada");

// }
// Serial.println(strcat(palavra2, "-SP"));
// // concatena duas strings, ou seja junta 

//--------------- FUNCOES PARA STRING ------------------
// Serial.println(palavra3.length());//retorna a quantidade de caracteres 
// Serial.print(palavra3.charAt(2));// retorna o caracter da posição indicada
// Serial.println(palavra3.substring(2, 5));//retorna um pedaço da string original
// Serial.println(palavra3.indexOf('M'));//retorna a posição do elemento procurado 
// Serial.println(palavra3.lastIndexOf('O'));//retorna a posição do ultimo elemento 

// if(palavra3.equalsIgnoreCase("ola mundo"))
// {Serial.println("iguais");}

// if(palavra3.startsWith("OLA"))
// {Serial.println("o inicio e igual");}

// if(palavra3.endsWith("DO"))
// {Serial.println("o fim e igual");}


// palavra3.toUpperCase();//converte para caixa alta
// palavra3.toLowerCase();//converte para caixa baixa
// Serial.println(palavra3);

// String valor = "100";
//int numero = valor.toInt();
// float numeroF = valor.toFloat();

// String texto = "texto     ";
// texto.trim();

// String instrucao = "Led = ON";
// instrucao.replace("ON", "OFF");

// Serial.setTimeout(5000);
// String texto = Serial.readStringUntil('\n');
// texto.trim();
// Serial.printf("voce digitou %s!", texto);


  //exercicio 1

// Serial.setTimeout(5000);
//  String texto = Serial.readStringUntil('\n');
// texto.trim();
//   Serial.printf("VOCE DIGITOU %s!", texto);
//   texto.toUpperCase();
//  if (texto.endsWith("ON"))
//  {Serial.println("LIGAR LED");
//  }
//  else if (texto.endsWith("OFF"))
//  {Serial.println("DESLIGAR LED");
//  }
//  else{
//  Serial.println("COMANDO INVÁLIDO");
//  }

// }


// void loop(){

// }

//exercicio 2

// String mensagem = "Temperatura = 27C";

// String temperatura = mensagem.substring (14, 16);

// int temperatura2 = temperatura.toInt();

// float FH = 80.6;

// Serial.printf ("tmp : %i, FH: %f", temperatura2, FH);

// }

// void loop(){

// }

//exercicio 3

// Serial.setTimeout(5000);
// char frase[] = "ESTAMOS APRENDENDO ARDUINO NA AULA";
 
//  if (strstr(frase, "ARDUINO"))
//  {
//   Serial.println("CONTEÚDO RELACIONADO A ARDUINO DETECTADO");
//  }else{
//  Serial.println("NÃO ENCONTRADO");
//  }
// }

// void loop(){

// }

//exercicio 4

// String frase = "SENAI eSp32 ArDuInO";

//  frase.toUpperCase();
//   Serial.println (frase);


//  frase.toLowerCase();
//    Serial.println (frase);

// frase.setCharAt (0, toupper(frase.charAt(0)));

// Serial.println(frase);
// }

// void loop(){

// }