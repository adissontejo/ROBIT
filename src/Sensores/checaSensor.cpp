#include "Sensor.h"

int Sensor::checaSensor(){ // função para checar qual o tipo do sensor informado  
  pinMode(this->d1, INPUT); // as duas portas digitais de checagem são definidas como entrada
  pinMode(this->d2, INPUT);
  
  bool d1 = digitalRead(this->d1);
  bool d2 = digitalRead(this->d2); // se faz a leitura destas duas portas
  
  if(!d1 and !d2){ // se a leitura apresentar dois valores baixos, o sensor é de cor
    pinMode(this->d1, OUTPUT); // as portas digitais utilizadas pelo sensor são definidas como saída 
    pinMode(this->d2, OUTPUT);
    pinMode(this->d3, OUTPUT);
    return 2; // é retornado o número equivalente ao tipo do sensor
  }else if(d2){ // se a leitura apresentar o segundo valor alto, o sensor é ultrassom
    pinMode(this->d1, OUTPUT); // as portas digitais utilizadas pelo sensor são definidas como saída
    pinMode(this->d3, OUTPUT);
    return 1; // é retornado o número equivalente ao tipo do sensor
  }else{ // caso contrário de ambas as condições, o sensor é de luz
    // nenhuma porta digital é definida pois estas não são utilizadas pelo sensor
    return 3; // é retornado o número equivalente ao tipo do sensor   
  }
}