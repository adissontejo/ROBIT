#include "Sensor.h"

int Sensor::obterCores(int corUtilizada = media){
  if(this->checaSensor() != cor){ // se o sensor da porta não for um sensor de cor
    return -1; // retorna -1 (mensagem de erro)
  }
  
  int leituraVermelho = 0, leituraVerde = 0, leituraAzul = 0; // valores que serão lidos na presença de luz vermelha, azul e verde;
 
  digitalWrite(this->d1, HIGH); // o led vermelho é ligado
  delay(10);
  leituraVermelho = analogRead(this->a1); // a leitura é atribuída à variável respectiva
  digitalWrite(this->d1, LOW); // o led vermelho é desligado
  delay(10);
  
  digitalWrite(this->d2, HIGH); // o led verde é ligado
  delay(10);
  leituraVerde = analogRead(this->a1); // a leitura é atribuída à variável respectiva
  digitalWrite(this->d2, LOW); // o led verde é desligado
  delay(10);
  
  digitalWrite(this->d3, HIGH); // o led azul é ligado
  delay(10);
  leituraAzul = analogRead(this->a1); // a leitura é atribuída à variável respectiva
  digitalWrite(this->d3, LOW); // o led azul é desligado
  delay(10);

  if(corUtilizada == vermelho){
    return leituraVermelho;
  } else if(corUtilizada == azul){
    return leituraAzul;
  } else if(corUtilizada == verde){
    return leituraVerde;
  }
  
  return (leituraVermelho + leituraAzul + leituraVerde)/3;
}