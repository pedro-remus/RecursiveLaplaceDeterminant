#include "ESMapeadaNaMemoria.h"
#include "Dispositivo.h"
#include <vector>
#include <stdexcept>

using namespace std;

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m) {
    memoriaDISP = NULL;
    memoriaRAM = m;
    tamanhoRAM = m->getTamanho();
}

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos) {
    memoriaRAM = m;
    tamanhoRAM = m->getTamanho();
    memoriaDISP = dispositivos;
}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria() {
    delete memoriaRAM;
    for (unsigned int i = 0; i < memoriaDISP->size(); i++)
        delete (*memoriaDISP)[i];
    delete memoriaDISP;
}

MemoriaRAM* ESMapeadaNaMemoria::getMemoriaSubjacente() {
    return memoriaRAM;
}

void ESMapeadaNaMemoria::adicionar(Dispositivo* d) {
    if (memoriaDISP == NULL)
        memoriaDISP = new vector<Dispositivo*>();
    memoriaDISP->push_back(d);
}

vector<Dispositivo*>* ESMapeadaNaMemoria::getDispositivos() {
    return memoriaDISP;
}

int ESMapeadaNaMemoria::getTamanho() {
    return tamanhoRAM + memoriaDISP->size(); 
}

Dado* ESMapeadaNaMemoria::ler(int posicao) {
    if (posicao < 0 || posicao > (tamanhoRAM + (int) memoriaDISP->size()))
        throw new logic_error("Posicao invalida da ESMapeadaNaMemoria");
    
    if (posicao < tamanhoRAM)
        return memoriaRAM->ler(posicao);
    else    
        return (*memoriaDISP)[posicao - tamanhoRAM]->ler();
}

void ESMapeadaNaMemoria::escrever(int posicao, Dado* d) {
    if (posicao < tamanhoRAM)
        memoriaRAM->escrever(posicao, d);
    else
        (*memoriaDISP)[posicao - tamanhoRAM]->escrever(d);
}

void ESMapeadaNaMemoria::imprimir() {
    memoriaRAM->imprimir();
}
