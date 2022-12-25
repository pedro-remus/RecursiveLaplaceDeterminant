#ifndef MONITOR
#define MONITOR

#include "Dispositivo.h"
#include "Dado.h"

class Monitor : public Dispositivo {
public:
    Monitor();
    virtual ~Monitor();
    virtual Dado* ler();
    virtual void escrever(Dado* d);
};

#endif // MONITOR