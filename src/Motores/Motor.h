#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
  public:
    Motor(int portaA, int portaB = -1);
    void frente(int tempo = -1);
    void tras(int tempo = -1);
    void para(int tempo = 0);
  private:
    int d1, d2, d3 = -1, d4 = -1;
};

#endif
