#include "BancoDeRegistradores.h"
#include <iostream>
#include <stdexcept>

using namespace std;

BancoDeRegistradores::BancoDeRegistradores() {
    registradores = new int[tamanho];
    for (int i = 0; i < tamanho; i++)
        registradores[i] = 0;
}

BancoDeRegistradores::~BancoDeRegistradores() {
    delete[] registradores;
}

int BancoDeRegistradores::getValor(int registrador) {
    if (registrador < 0 || registrador >= tamanho)
        throw new logic_error("posicao de registrador invalida");
    return registradores[registrador];        
}

void BancoDeRegistradores::setValor(int registrador, int valor) {
    if (registrador < 0 || registrador >= tamanho)
        throw new logic_error("posicao de registrador invalida");
    else if(registrador == 0) return;
    else registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir() {
    for (int i = 0; i < tamanho; i++)
        cout << i << ": " << registradores[i] << endl;
}