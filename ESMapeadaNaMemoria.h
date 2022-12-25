#ifndef ES_MAPEADA_NA_MEMORIA
#define ES_MAPEADA_NA_MEMORIA

#include "MemoriaRAM.h"
#include "Dispositivo.h"
#include <vector>


using namespace std;

class ESMapeadaNaMemoria : public Memoria {
private:
    MemoriaRAM* memoriaRAM;
    vector <Dispositivo*>* memoriaDISP;
    int tamanhoRAM;
public:
    ESMapeadaNaMemoria(MemoriaRAM* m);
    ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos); 
    virtual ~ESMapeadaNaMemoria(); 
    virtual MemoriaRAM* getMemoriaSubjacente(); 
    virtual void adicionar(Dispositivo* d); 
    virtual vector<Dispositivo*>* getDispositivos(); 
    virtual int getTamanho();
    virtual Dado* ler(int posicao);
    virtual void escrever(int posicao, Dado* d);
    virtual void imprimir();
};

#endif // ES_MAPEADA_NA_MEMORIA