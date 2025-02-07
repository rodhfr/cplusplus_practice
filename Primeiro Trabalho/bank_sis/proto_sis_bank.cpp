#include <iostream>
#include <string>
using namespace std;


class contaBancaria {
private:
    string nome_cliente;
    int n_conta;
    float saldo;
public:
    contaBancaria(string nome_usr, float deposito_inicial){
        nome_cliente = nome_usr;
        saldo = deposito_inicial;
        n_conta = rand();
    }
    ~contaBancaria() {}
    void sts_opr(bool sucesso){
        if (sucesso) { cout << "Operacao Realizada com Sucesso!" << endl; }
        else { cout << "Operacao falhou" << endl; }
    }
    void extrato() {
        cout << "O saldo da conta " << n_conta << " do cliente " << nome_cliente;
        cout << " e de " << saldo << " R$" << endl;
    }
    void depositar(float quantia) {
        saldo += quantia;
        sts_opr(true);
        cout << "Depositado " << quantia << "R$" << endl;
        extrato(); 
    }
    void sacar(float quantia) {
        if (quantia <= saldo) {
            saldo -= quantia;
            sts_opr(true);
            cout << "Sacado " << quantia << "R$" << endl;
            extrato();
        }
        else { sts_opr(false); }
    }

};

int main(void) {

    contaBancaria u1("Astolfo", 0);
    u1.depositar(500);
    u1.sacar(200);
    u1.sacar(2000);

    return 0;
}