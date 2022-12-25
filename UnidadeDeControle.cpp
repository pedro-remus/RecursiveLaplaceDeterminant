#include "UnidadeDeControle.h"
#include "Memoria.h"
#include "ESMapeadaNaMemoria.h"
#include "Instrucao.h"
#include <iostream>

using namespace std;

// MÉTODOS PRIVADOS

void UnidadeDeControle::addInstrucao(int destino, int origem1, int origem2) {
    registradores->setValor(destino, registradores->getValor(origem1) + registradores->getValor(origem2));
    pc++;
}

void UnidadeDeControle::subInstrucao(int destino, int origem1, int origem2) {
    registradores->setValor(destino, registradores->getValor(origem1) - registradores->getValor(origem2));
    pc++;
}

void UnidadeDeControle::multInstrucao(int origem1, int origem2) {
    registradores->setValor(24, registradores->getValor(origem1) * registradores->getValor(origem2));
    pc++;
}

void UnidadeDeControle::divInstrucao(int origem1, int origem2) {
    registradores->setValor(24, registradores->getValor(origem1) / registradores->getValor(origem2));
    registradores->setValor(25, registradores->getValor(origem1) % registradores->getValor(origem2));
    pc++;
}

void UnidadeDeControle::jInstrucao(int imediato) {
    setPC(imediato);
}

void UnidadeDeControle::bneInstrucao(int origem1, int origem2, int imediato) {
    if (registradores->getValor(origem1) != registradores->getValor(origem2))
        setPC(imediato);
    else pc++;
}

void UnidadeDeControle::beqInstrucao(int origem1, int origem2, int imediato) {
    if (registradores->getValor(origem1) == registradores->getValor(origem2))
        setPC(imediato);
    else pc++;    
}

void UnidadeDeControle::lwInstrucao(int destino, int imediato) {
    Dado* d = memoria->ler(imediato);
    if (d == NULL)
        registradores->setValor(destino, 0);
    else
        registradores->setValor(destino, d->getValor());
    pc++;
}

void UnidadeDeControle::swInstrucao(int destino, int imediato) {
    memoria->escrever(imediato, new Dado(registradores->getValor(destino)));
    pc++;
}

// MÉTODOS PÚBLICOS

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria) {
    this->pc = 0;
    this->registradores = registradores;
    this->memoria = memoria;
}

UnidadeDeControle::~UnidadeDeControle() {
    delete registradores;
    delete memoria;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores() {
    return registradores;
}

Memoria* UnidadeDeControle::getMemoria() {
    return memoria;
}

int UnidadeDeControle::getPC() {
    return pc;
}

void UnidadeDeControle::setPC(int pc) {
    this->pc = pc;
} 

void UnidadeDeControle::executarInstrucao() {
    while (dynamic_cast<Instrucao*>(memoria->ler(pc)) == NULL) {
       pc++;
       return;
    }
    Instrucao* instrucao = dynamic_cast<Instrucao*>(memoria->ler(pc));
    int opcode = instrucao->getOpcode();
    int funcao = instrucao->getFuncao();
    int origem1 = instrucao->getOrigem1();
    int origem2 = instrucao->getOrigem2();
    int destino = instrucao->getDestino();
    int imediato = instrucao->getImediato();

    if(opcode == Instrucao::TIPO_R) {
        if (funcao == Instrucao::FUNCAO_ADD)
            addInstrucao(destino, origem1, origem2);
        else if (funcao == Instrucao::FUNCAO_SUB)
            subInstrucao(destino, origem1, origem2);
        else if (funcao == Instrucao::FUNCAO_MULT) 
            multInstrucao(origem1, origem2);
        else if (funcao == Instrucao::FUNCAO_DIV) 
            divInstrucao(origem1, origem2);
    } 
    else if (opcode == Instrucao::J) 
        jInstrucao(imediato);
    else if (opcode == Instrucao::BNE) 
        bneInstrucao(origem1, origem2, imediato);
    else if (opcode == Instrucao::BEQ) 
        beqInstrucao(origem1, origem2, imediato);
    else if (opcode == Instrucao::LW) 
        lwInstrucao(destino, imediato);
    else if (opcode == Instrucao::SW) 
        swInstrucao(destino, imediato);
}