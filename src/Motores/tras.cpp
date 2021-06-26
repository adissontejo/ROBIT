#include "Motor.h"

void Motor::tras(int tempo) {
  digitalWrite(this->d1, LOW);
  digitalWrite(this->d2, HIGH);

  if (this->d3 != -1 && this->d4 != -1) {
    digitalWrite(this->d3, LOW);
    digitalWrite(this->d3, HIGH);
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