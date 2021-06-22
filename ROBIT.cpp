#include <Arduino.h>
#include "Ultrasonic.h"
#include "ROBIT.h"

#define ultrassom 1 //definição dos tipos de sensores como números
#define cor 2
#define luz 3

sensor::sensor(int porta){
  this->d1 = porta*3 - 2;
  this->d2 = porta*3 - 1;
  this->d3 = porta*3;
  this->a1 = 13 + porta;
}

int sensor::checaSensor(){ // função para checar qual o tipo do sensor informado
  pinMode(this->d1, INPUT); // as duas portas digitais de checagem são definidas como entrada
  pinMode(this->d2, INPUT);
  bool d1 = digitalRead(this->d1);
  bool d2 = digitalRead(this->d2); // se faz a leitura destas duas portas
  if(!d1 and !d2){ // se a leitura apresentar dois valores baixos, o sensor é de cor
    pinMode(this->d1, OUTPUT); // as portas digitais utilizadas pelo sensor são definidas como saída 
    pinMode(this->d2, OUTPUT);
    pinMode(this->d3, OUTPUT);
    return cor; // é retornado o número equivalente ao tipo do sensor
  }else if(d2){ // se a leitura apresentar o segundo valor alto, o sensor é ultrassom
    pinMode(this->d1, OUTPUT); // as portas digitais utilizadas pelo sensor são definidas como saída
    pinMode(this->d3, OUTPUT);
    return ultrassom; // é retornado o número equivalente ao tipo do sensor
  }else{ // caso contrário de ambas as condições, o sensor é de luz
    // nenhuma porta digital é definida pois estas não são utilizadas pelo sensor
    return luz; // é retornado o número equivalente ao tipo do sensor   
  }
}

int sensor::obterDistancia(){
  if(this->checaSensor() != ultrassom){ // se o sensor da porta não for um sensor ultrassom
    return -1; // retorna -1 (mensagem de erro)
  } // o sensor ultrassom é definido
  Ultrasonic sensor(this->d1, this->d3); // o sensor ultrassom é definido
  return sensor.read(); // é obtida e retornada a distância através da biblioteca
}

int sensor::obterCores(int corUtilizada){
  if(this->checaSensor() != cor){ // se o sensor da porta não for um sensor de cor
    return -1; // retorna -1 (mensagem de erro)
  }
  int leituraVermelho = 0, leituraVerde = 0, leituraAzul = 0; // valores que serão lidos na presença de luz vermelha, azul e verde;
  digitalWrite(this->d1, HIGH); // o led vermelho é ligado
  delay(10);
  leituraVermelho = analogRead(this->a1); // a leitura é atribuída à variável respectiva
  digitalWrite(this->d1, LOW); // o led vermelho é desligado
  delay(10);
  digitalWrite(this->d2, HIGH); // o led verde é ligado
  delay(10);
  leituraVerde = analogRead(this->a1); // a leitura é atribuída à variável respectiva
  digitalWrite(this->d2, LOW); // o led verde é desligado
  delay(10);
  digitalWrite(this->d3, HIGH); // o led azul é ligado
  delay(10);
  leituraAzul = analogRead(this->a1); // a leitura é atribuída à variável respectiva
  digitalWrite(this->d3, LOW); // o led azul é desligado
  delay(10);
  switch(corUtilizada){ 
    case 1: // caso a leitura requisitada seja na luz vermelha
      return leituraVermelho; // é retornado o valor da leitura na luz vermelha
      break;
    case 2: // caso a leitura requisitada seja na luz azul
      return leituraAzul; // é retornado o valor da leitura na luz azul
      break;
    case 3: // caso a leitura requisitada seja na luz verde
      return leituraVerde; // é retornado o valor da leitura na luz verde
      break;
    default: // caso contrário de ambas as condições
      return (leituraVermelho + leituraAzul + leituraVerde)/3; // é retornada a média das leituras
      break;
  }
}

int sensor::obterLuz(){
  if(this->checaSensor() != luz){
    return -1;
  }
  return analogRead(this->a1);
}
