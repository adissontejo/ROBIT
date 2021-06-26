#include "Motor.h"

Motor::Motor(int portaA, int portaB = -1){
  this->d1 = 7*portaA;
  this->d2 = 7*portaA + 1;

  pinMode(this->d1, OUTPUT);
  pinMode(this->d2, OUTPUT);

  if (portaB != -1) {
    this->d3 = 7*portaB;
    this->d4 = 7*portaB + 1;
    
    pinMode(this->d3, OUTPUT);
    pinMode(this->d4, OUTPUT);
  }
}