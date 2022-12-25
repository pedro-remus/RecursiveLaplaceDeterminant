#ifndef MEMORIA
#define MEMORIA
#include "Dado.h"

class Memoria {

public:
    Memoria();
    virtual ~Memoria(); 
    virtual int getTamanho() = 0; 
    virtual Dado* ler(int posicao) = 0; 
    virtual void escrever(int posicao, Dado* d) = 0; 
    virtual void imprimir() = 0; 
};

#endif // MEMORIA