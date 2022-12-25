#include "TecladoDeChar.h"
#include <iostream>

using namespace std;

TecladoDeChar::TecladoDeChar() : Teclado() {
}

TecladoDeChar::~TecladoDeChar() {
}

Dado* TecladoDeChar::ler() {
    cout << "Digite um caractere: ";
    char c;
    cin >> c;
    return new Dado((int) c);
}