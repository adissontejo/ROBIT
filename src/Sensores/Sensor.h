#ifndef SENSOR_H
#define SENSOR_h

#include "Arduino.h"

extern int distancia;
extern int cor;
extern int luz;
 
extern int vermelho;
extern int verde;
extern int azul;
extern int media;

class Sensor {
  public:
    Sensor(int porta);
    int obterDistancia();
    int obterCores(int corUtilizada);
    int obterLuz();
  private:
    int d1, d2, d3, a1;
    int checaSensor();
};

#endif
