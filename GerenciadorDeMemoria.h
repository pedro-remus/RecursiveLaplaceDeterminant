#ifndef GERENCIADOR_DE_MEMORIA
#define GERENCIADOR_DE_MEMORIA

#include <string>
#include "MemoriaRAM.h"

class GerenciadorDeMemoria {
public:
    GerenciadorDeMemoria();
    virtual ~GerenciadorDeMemoria();
    virtual void load(string arquivo, MemoriaRAM* m); 
    virtual void dump(string arquivo, MemoriaRAM* m);
};

#endif // GERENCIADOR_DE_MEMORIA