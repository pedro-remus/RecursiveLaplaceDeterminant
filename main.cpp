#include <iostream>
#include "BancoDeRegistradores.h"
#include "MemoriaRAM.h"
#include "ESMapeadaNaMemoria.h"
#include "Monitor.h"
#include "MonitorDeChar.h"
#include "Teclado.h"
#include "TecladoDeChar.h"
#include "UnidadeDeControle.h"
#include "GerenciadorDeMemoria.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void interfaceMemoria(Memoria* memoria) {
    int opcao = -1;
    int posicao, valor;
    while (opcao != 0) {
        cout << "Memoria de Dados" << endl;
        cout << "1) Alterar dado" << endl;
        cout << "2) Imprimir" << endl;
        cout << "0) Voltar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout << endl;

        if (opcao == 1) {
            cout << "Posicao a ser alterada: ";
            cin >> posicao;
            cout << "Novo valor: ";
            cin >> valor;
            cout << endl;

            delete memoria->ler(posicao);
            memoria->escrever(posicao, new Dado(valor)); // substitui o dado na posicao 'posicao' por um novo dado de valor 'valor'
        }
        if (opcao == 2) {
            memoria->imprimir();
            cout << endl;
        }
    }
}

void interfaceBRegistradores(BancoDeRegistradores* registradores) {
    int opcao = -1;
    int registrador, valor;
    while (opcao != 0) {
        cout << "Registradores" << endl;
        cout << "1) Alterar valor" << endl;
        cout << "2) Imprimir" << endl;
        cout << "0) Voltar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout << endl;
        
        if (opcao == 1) {
            cout << "Registrador a ser alterado: ";
            cin >> registrador;
            cout << "Novo valor: ";
            cin >> valor;
            cout << endl;

            registradores->setValor(registrador, valor); // substitui o valor do registrador 'registrador' pelo valor 'valor'
        }
        if (opcao == 2) {
            registradores->imprimir();
            cout << endl;
        }
    }
}

void interfaceInstrucao(UnidadeDeControle* UC) {
    try {
        cout << "PC: " << UC->getPC() << endl;
        UC->executarInstrucao();
        cout << "Instrucao executada" << endl;
        cout << "PC: " << UC->getPC() << endl;
        cout << endl;
    } catch (logic_error* e) {
        cout << e->what() << endl;
        delete e;
        cout << endl;
    } catch (runtime_error* e) {
        cout << e->what() << endl;
        delete e;
        cout << endl;
    }
}

void interfaceInstrucaoAte0(UnidadeDeControle* UC) {
    try {
        do {
            UC->executarInstrucao();
        } while (UC->getPC() != 0);
        cout << endl;
    } catch (logic_error* e) {
        cout << e->what() << endl;
        delete e;
        cout << endl;
    } catch (runtime_error* e) {
        cout << e->what() << endl;
        delete e;
        cout << endl;
    }    
}

void interfaceLoad(UnidadeDeControle* UC) {
    try {
        string arquivo;
        cout << "Arquivo origem: ";
        cin >> arquivo;
        cout << endl;
        GerenciadorDeMemoria* gerenciador = new GerenciadorDeMemoria();
        gerenciador->load(arquivo, dynamic_cast<ESMapeadaNaMemoria*>(UC->getMemoria())->getMemoriaSubjacente());
        delete gerenciador;
    } catch (logic_error* e) {
        cout << e->what() << endl;
        delete e;
        cout << endl;
    } catch (runtime_error* e) {
        cout << e->what() << endl;
        delete e;
        cout << endl;
    }  
}

void interfaceDump(UnidadeDeControle* UC) {
    try {
        string arquivo;
        cout << "Arquivo destino: ";
        cin >> arquivo;
        cout << endl;
        GerenciadorDeMemoria* gerenciador = new GerenciadorDeMemoria();
        gerenciador->dump(arquivo, dynamic_cast<ESMapeadaNaMemoria*>(UC->getMemoria())->getMemoriaSubjacente());
        delete gerenciador;
    } catch (logic_error* e) {
        cout << e->what() << endl;
        delete e;
        cout << endl;
    } catch (runtime_error* e) {
        cout << e->what() << endl;
        delete e;
        cout << endl;
    } 
}

void interfaceMenuInicial(UnidadeDeControle* UC) {
    int opcao = -1;
    while (opcao != 0) {
        cout << "Emulador de MIPS" << endl;
        cout << "1) Memoria" << endl;
        cout << "2) Registradores" << endl;
        cout << "3) Executar proxima instrucao" << endl;
        cout << "4) Executar ate PC = 0" << endl;
        cout << "5) Load" << endl;
        cout << "6) Dump" << endl;
        cout << "0) Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout << endl;

        if (opcao == 1)
            interfaceMemoria(UC->getMemoria());
        else if (opcao == 2)
            interfaceBRegistradores(UC->getBancoDeRegistradores());
        else if (opcao == 3)
            interfaceInstrucao(UC);
        else if (opcao == 4)
            interfaceInstrucaoAte0(UC);
        else if (opcao == 5)
            interfaceLoad(UC);
        else if (opcao == 6)
            interfaceDump(UC);
    }
    delete UC;
}

int main() {
    BancoDeRegistradores* registradores = new BancoDeRegistradores();
    MemoriaRAM* memoriaRAM = new MemoriaRAM(64);
    ESMapeadaNaMemoria* esMap = new ESMapeadaNaMemoria(memoriaRAM);
    esMap->adicionar(new Teclado());
    esMap->adicionar(new TecladoDeChar());
    esMap->adicionar(new Monitor());
    esMap->adicionar(new MonitorDeChar());

    UnidadeDeControle* UC = new UnidadeDeControle(registradores, esMap);
    interfaceMenuInicial(UC);
    return 0;
}
