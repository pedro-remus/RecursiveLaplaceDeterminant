#ifndef TECLADO
#define TECLADO

#include "Dispositivo.h"

class Teclado : public Dispositivo {
public:
    Teclado();
    virtual ~Teclado();
    virtual Dado* ler();
    virtual void escrever(Dado* d);
};

#endif // TECLADO