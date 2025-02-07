#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>
using namespace std;

class contaBancaria {
private:
    string nome_cliente;
    int n_conta;
    float saldo;

public:
    contaBancaria(string nome_usr, float deposito_inicial);
    ~contaBancaria();

    void sts_opr(bool sucesso);
    void extrato();
    void depositar(float quantia);
    void sacar(float quantia);
};

#endif
