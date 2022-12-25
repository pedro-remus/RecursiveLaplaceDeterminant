#ifndef MEMORIA_RAM
#define MEMORIA_RAM

#include "Memoria.h"
#include "Dado.h"
#include <list>

using namespace std;

class MemoriaRAM : public Memoria {
private:
    int tamanho;
    Dado** dadosRAM;
public:
    MemoriaRAM(int tamanho);
    virtual ~MemoriaRAM(); 
    virtual void escrever(list<Dado*>* dados);
    virtual void escrever(int posicao, Dado* d);
    virtual Dado* ler(int posicao);
    virtual void imprimir();
    virtual int getTamanho();
};

#endif // MEMORIA_RAM