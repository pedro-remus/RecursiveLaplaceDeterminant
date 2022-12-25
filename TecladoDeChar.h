#ifndef TECLADO_DE_CHAR
#define TECLADO_DE_CHAR

#include "Teclado.h"

class TecladoDeChar : public Teclado {
public:
    TecladoDeChar();
    virtual ~TecladoDeChar();
    virtual Dado* ler();
};

#endif // TECLADO_DE_CHAR