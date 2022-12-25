#ifndef BANCODEREGISTRADORES_H
#define BANCODEREGISTRADORES_H
#define QUANTIDADE_REGISTRADORES 32

class BancoDeRegistradores {
private:
  int tamanho = QUANTIDADE_REGISTRADORES;
  int *registradores;

public:
  BancoDeRegistradores(); 
  virtual ~BancoDeRegistradores(); 
  virtual int getValor(int registrador); // joga exceções
  virtual void setValor(int registrador, int valor); // joga exceções
  virtual void imprimir();
};

#endif // BANCODEREGISTRADORES_H