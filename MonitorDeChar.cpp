#include "MonitorDeChar.h"
#include <iostream>

using namespace std;

MonitorDeChar::MonitorDeChar() : Monitor() {
}

MonitorDeChar::~MonitorDeChar() {
}

void MonitorDeChar::escrever(Dado* d) {
    cout << (char) d->getValor();
}