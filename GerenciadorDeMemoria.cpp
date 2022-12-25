#include "GerenciadorDeMemoria.h"
#include "Dado.h"
#include "Instrucao.h"
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>

using namespace std;

GerenciadorDeMemoria::GerenciadorDeMemoria() {
}

GerenciadorDeMemoria::~GerenciadorDeMemoria() {
}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM* m) {
    ifstream input;
    input.open(arquivo);

    if (input.fail())
        throw new runtime_error("Erro de leitura (arquivo n encontrado)");

    int tamanho;
    input >> tamanho;
    if (input.eof() || input.fail())
        throw new runtime_error("Arquivo Vazio");

    string tipo;
    int i = 0;
    int origem1, origem2, destino, imediato; 
    
    while (input && i < tamanho) {
        input >> tipo;
        if (tipo == "-") {
            m->escrever(i, NULL);
        }
        else if (tipo == "D") {
            int valor;
            input >> valor;
            m->escrever(i, new Dado(valor));
        } else {
            if (tipo == "ADD") {
                input >> destino >> origem1 >> origem2;
                m->escrever(i, Instrucao::criarADD(destino, origem1, origem2));
            }
            else if (tipo == "SUB") {
                input >> destino >> origem1 >> origem2;
                m->escrever(i, Instrucao::criarSUB(destino, origem1, origem2));
            }
            else if (tipo == "MULT") {
                input >> origem1 >> origem2;
                m->escrever(i, Instrucao::criarMULT(origem1, origem2));
            }
            else if (tipo == "DIV") {
                input >> origem1 >> origem2;
                m->escrever(i, Instrucao::criarDIV(origem1, origem2));
            }
            else if (tipo == "LW") {
                input >> destino >> imediato;
                m->escrever(i, Instrucao::criarLW(destino, imediato));
            }
            else if (tipo == "SW") {
                input >> destino >> imediato;
                m->escrever(i, Instrucao::criarSW(destino, imediato));
            }
            else if (tipo == "J") {
                input >> imediato;
                m->escrever(i, Instrucao::criarJ(imediato));
            }
            else if (tipo == "BNE") {
                input >> origem1 >> origem2 >> imediato;
                m->escrever(i, Instrucao::criarBNE(origem1, origem2, imediato));
            }
            else if (tipo == "BEQ") {
                input >> origem1 >> origem2 >> imediato;
                m->escrever(i, Instrucao::criarBEQ(origem1, origem2, imediato));
            }
        }
        i++;
    }
    input >> tipo;
    if (!input.eof())
        throw new runtime_error("Erro durante a leitura do arquivo");
    input.close();
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM* m) {
    ofstream output;
    output.open(arquivo);

    if (output.fail())
        throw new runtime_error("Erro ao escrever no arquivo");
    for (int i = 0; i < m->getTamanho(); i++) {
        if (m->ler(i) == NULL)
            output << "-";
        else if (dynamic_cast<Instrucao*>(m->ler(i)) == NULL)
            output << "D " << m->ler(i)->getValor();
        else {
            Instrucao* instrucao = dynamic_cast<Instrucao*>(m->ler(i));
            int opcode = instrucao->getOpcode();
            int funcao = instrucao->getFuncao();
            int origem1 = instrucao->getOrigem1();
            int origem2 = instrucao->getOrigem2();
            int destino = instrucao->getDestino();
            int imediato = instrucao->getImediato();
            if (opcode == Instrucao::TIPO_R) {
                if (funcao == Instrucao::FUNCAO_ADD)
                    output << "ADD " << destino << " " << origem1 << " " << origem2;
                else if (funcao == Instrucao::FUNCAO_SUB)
                    output << "SUB " << destino << " " << origem1 << " " << origem2;
                else if (funcao == Instrucao::FUNCAO_MULT)
                    output << "MULT " << origem1 << " " << origem2;
                else if (funcao == Instrucao::FUNCAO_DIV)
                    output << "DIV " << origem1 << " " << origem2;
            }
            else if (opcode == Instrucao::J)
                output << "J " << imediato;
            else if (opcode == Instrucao::BNE)
                output << "BNE " << origem1 << " " << origem2 << " " << imediato;
            else if (opcode == Instrucao::BEQ)
                output << "BEQ " << origem1 << " " << origem2 << " " << imediato;
            else if (opcode == Instrucao::LW)
                output << "LW " << destino << " " << imediato;
            else if (opcode == Instrucao::SW)
                output << "SW " << destino << " " << imediato;
        }
        output << endl;
    }
    output.close();
}