#include "contaBancaria.h"
#include <iostream>
#include <cstdlib> // Para rand()

using namespace std;

contaBancaria::contaBancaria(string nome_usr, float deposito_inicial) {
    nome_cliente = nome_usr;
    saldo = deposito_inicial;
    n_conta = rand();
}

contaBancaria::~contaBancaria() {}

void contaBancaria::sts_opr(bool sucesso) {
    if (sucesso) {
        cout << "Operacao Realizada com Sucesso!" << endl;
    } else {
        cout << "Operacao falhou" << endl;
    }
}

void contaBancaria::extrato() {
    cout << "O saldo da conta " << n_conta << " do cliente " << nome_cliente;
    cout << " e de " << saldo << " R$" << endl;
}

void contaBancaria::depositar(float quantia) {
    saldo += quantia;
    sts_opr(true);
    cout << "Depositado " << quantia << "R$" << endl;
    extrato();
}

void contaBancaria::sacar(float quantia) {
    if (quantia <= saldo) {
        saldo -= quantia;
        sts_opr(true);
        cout << "Sacado " << quantia << "R$" << endl;
        extrato();
    } else {
        sts_opr(false);
    }
}
