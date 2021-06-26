#include "Sensor.h"

int distancia = 1;
int cor = 2;
int luz = 3;

int vermelho = 1;
int verde = 2;
int azul = 3;
int media = 4;

Sensor::Sensor(int porta){
  this->d1 = porta*3 - 2;
  this->d2 = porta*3 - 1;
  this->d3 = porta*3;
  this->a1 = 13 + porta;
}