#include "Sensor.h"

int Sensor::obterLuz(){
  if(this->checaSensor() != luz){
    return -1;
  }
  return analogRead(this->a1);
}