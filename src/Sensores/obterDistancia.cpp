#include "Sensor.h"
#include "Ultrasonic.h"

int Sensor::obterDistancia(){
  if(this->checaSensor() != distancia){ // se o sensor da porta não for um sensor ultrassom
    return -1; // retorna -1 (mensagem de erro)
  } // o sensor ultrassom é definido
  Ultrasonic sensor(this->d1, this->d3); // o sensor ultrassom é definido
  return sensor.read(); // é obtida e retornada a distância através da biblioteca
}