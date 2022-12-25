#include "Instrucao.h"
#include <iostream>

using namespace std;

Instrucao::Instrucao(int opcode, int origem1, int origem2, 
                     int destino, int imediato, int funcao) : Dado(opcode) {
    this->opcode = opcode;
    this->origem1 = origem1;
    this->origem2 = origem2;
    this->destino = destino;
    this->imediato = imediato;
    this->funcao = funcao;
}

Instrucao::~Instrucao() { 
}


Instrucao* Instrucao::criarLW(int destino, int imediato) {
    return new Instrucao(LW, -1, -1, destino, imediato, -1);
}

Instrucao* Instrucao::criarSW(int destino, int imediato) {
    return new Instrucao(SW, -1, -1, destino, imediato, -1);
}

Instrucao* Instrucao::criarJ(int imediato) {
    return new Instrucao(J, -1, -1, -1, imediato, -1);
}

Instrucao* Instrucao::criarBNE(int origem1, int origem2, int imediato) {
    return new Instrucao(BNE, origem1, origem2, -1, imediato, -1);
}

Instrucao* Instrucao::criarBEQ(int origem1, int origem2, int imediato) {
    return new Instrucao(BEQ, origem1, origem2, -1, imediato, -1);
}

Instrucao* Instrucao::criarADD(int destino, int origem1, int origem2) {
    return new Instrucao(TIPO_R, origem1, origem2, destino, -1, FUNCAO_ADD);
}

Instrucao* Instrucao::criarSUB(int destino, int origem1, int origem2) {
    return new Instrucao(TIPO_R, origem1, origem2, destino, -1, FUNCAO_SUB);
}

Instrucao* Instrucao::criarMULT(int origem1, int origem2) {
    return new Instrucao(TIPO_R, origem1, origem2, -1, -1, FUNCAO_MULT);
}

Instrucao* Instrucao::criarDIV(int origem1, int origem2) {
    return new Instrucao(TIPO_R, origem1, origem2, -1, -1, FUNCAO_DIV);
}

int Instrucao::getOpcode() {
    return opcode;
}

int Instrucao::getOrigem1() {
    return origem1;
}

int Instrucao::getOrigem2() {
    return origem2;
}

int Instrucao::getDestino() {
    return destino;
}

int  Instrucao::getImediato() {
    return imediato;
}

int Instrucao::getFuncao() {
    return funcao;
}

void Instrucao::imprimir() {
    cout << "Instrucao " << opcode;
}