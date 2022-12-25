#ifndef UNIDADEDECONTROLE_H
#define UNIDADEDECONTROLE_H

#include "BancoDeRegistradores.h"
#include "Memoria.h"
#include "ESMapeadaNaMemoria.h"

class UnidadeDeControle {
private:
  int pc;                               // contador de programa
  BancoDeRegistradores* registradores;
  Memoria* memoria;
  
  void addInstrucao(int destino, int origem1, int origem2);
  void subInstrucao(int destino, int origem1, int origem2);
  void multInstrucao(int origem1, int origem2);
  void divInstrucao(int origem1, int origem2);
  void jInstrucao(int imediato);
  void bneInstrucao(int origem1, int origem2, int imediato);
  void beqInstrucao(int origem1, int origem2, int imediato);
  void lwInstrucao(int destino, int imediato);
  void swInstrucao(int destino, int imediato);
  
public:
  UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria);
  virtual ~UnidadeDeControle(); 

  virtual BancoDeRegistradores* getBancoDeRegistradores(); 
  virtual Memoria* getMemoria(); 
  virtual int getPC(); 
  virtual void setPC(int pc); 
  virtual void executarInstrucao(); 
};


#endif // UNIDADEDECONTROLE_H