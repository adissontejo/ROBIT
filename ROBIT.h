#ifndef ROBIT_H
#define ROBIT_H

#include "Arduino.h"

class sensor {
  public:
    sensor(int porta);
    int obterDistancia();
    int obterCores(int corUtilizada);
    int obterLuz();
  private:
    int d1, d2, d3, a1;
    int checaSensor();
};

#endif
