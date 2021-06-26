#include "Motor.h"

void Motor::frente(int tempo) {
  digitalWrite(this->d1, HIGH);
  digitalWrite(this->d2, LOW);

  if (this->d3 != -1 && this->d4 != -1) {
    digitalWrite(this->d3, HIGH);
    digitalWrite(this->d3, LOW);
  }

  if (tempo != -1) {
    delay(tempo);
    digitalWrite(this->d1, LOW);
    digitalWrite(this->d2, LOW);

    if (this->d3 != -1 && this->d4 != -1) {
      digitalWrite(this->d3, LOW);
      digitalWrite(this->d3, LOW);
    }
  }
}