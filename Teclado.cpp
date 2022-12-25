#include "Teclado.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Teclado::Teclado() : Dispositivo() {
}

Teclado::~Teclado() {
}

void Teclado::escrever(Dado* d) {
    throw new logic_error("Nao se pode escrever dado em Teclado (dispositivo de entrada)");
}

Dado* Teclado::ler() {
    cout << "Digite um numero: ";
    int num;
    cin >> num;
    return new Dado(num);
}