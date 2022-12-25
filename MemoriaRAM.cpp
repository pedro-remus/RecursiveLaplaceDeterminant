#include "MemoriaRAM.h"
#include <iostream>
#include <stdexcept>

using namespace std;

MemoriaRAM::MemoriaRAM(int tamanho) : Memoria(), tamanho (tamanho) {
    dadosRAM  = new Dado*[tamanho];
    for (int i = 0; i < tamanho; i++)
        dadosRAM[i] = NULL;
    
}

MemoriaRAM::~MemoriaRAM() {
    for (int i = 0; i < tamanho; i++)
        if(dadosRAM[i] != NULL)
            delete dadosRAM[i];
    delete[] dadosRAM;
}

int MemoriaRAM::getTamanho() {
    return tamanho;
}

Dado* MemoriaRAM::ler(int posicao) {
    if (posicao < 0 || posicao >= tamanho)
        throw new logic_error("Posicao de memoria invalida");
    return dadosRAM[posicao];
}

void MemoriaRAM::escrever(list<Dado*>* dados) {
    if ((int) dados->size() > tamanho)
        throw new logic_error("List muito grande");
    list<Dado*>::iterator x = dados->begin();
    for (unsigned int i = 0; i < dados->size(); i++) {
        dadosRAM[i] = *x;
        x++;
    }
}

void MemoriaRAM::escrever(int posicao, Dado* d) {
    if (posicao < 0 || posicao >= tamanho)
        throw new logic_error("Posicao de memoria invalida");
    if (dadosRAM[posicao] != NULL)
        delete dadosRAM[posicao];
    dadosRAM[posicao] = d;
}

void MemoriaRAM::imprimir() {
    for (int i = 0; i < tamanho; i++) {
        cout << i << ": ";
        if (dadosRAM[i] == NULL)
            cout << "-";
        else 
            dadosRAM[i]->imprimir();
        cout << endl;
    }
}

