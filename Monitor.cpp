#include "Monitor.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Monitor::Monitor() : Dispositivo() {
}

Monitor::~Monitor() {
}

Dado* Monitor::ler() {
    throw new logic_error("Nao se pode ler dado em Monitor (dispositivo de saida)");
}

void Monitor::escrever(Dado* d) {
    cout << d->getValor();
}