#include "Motor.h"

void Motor::para(int tempo) {
  digitalWrite(this->d1, LOW);
  digitalWrite(this->d2, LOW);

  if (this->d3 != -1 && this->d4 != -1) {
    digitalWrite(this->d3, LOW);
    digitalWrite(this->d4, LOW);
  }

  delay(tempo);
}