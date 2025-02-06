#include <iostream>

class Carteira {
    private:
    char endereco[51];
    float btc = 0, eth = 0, brl = 0;

    void status_msg(bool sucesso) {
        if (sucesso) {
            std::cout << "Operação realizada com sucesso!" << std::endl;
        } 
        else {
            std::cout << "Erro na operação." << std::endl;
        }
    }

    void deposito(float quantia, int carteira_id) {
        std::cout << "-- Menu de Deposito --" << std::endl;
        if (quantia > 0) {
            switch (carteira_id) {
                case 1:
                    btc  += quantia;
                    status_msg(true);
                    break;
                case 2:
                    eth += quantia;
                    status_msg(true);
                    break;
                case 3:
                    brl += quantia;
                    status_msg(true);
                    break;
                default:
                    status_msg(false);
                    std::cout << "ID de carteira inválido!" << std::endl;
            }
        }
        else {
            std::cout << "Valor inválido para depósito!" << std::endl;
        }
    }
    
    void saque(float quantia, int carteira_id) {
        std::cout << "-- Menu de Saque --" << std::endl;
        if (quantia > 0) {
            switch (carteira_id) {
                case 1:
                    if (btc + quantia >= 0) btc -= quantia;
                    status_msg(true);
                    exibirSaldoBTC();
                    break;
                case 2:
                    if (eth + quantia >= 0) eth -= quantia;
                    status_msg(true);
                    exibirSaldoETH();
                    break;
                case 3:
                    if (brl + quantia >= 0) brl -= quantia;
                    status_msg(true);
                    exibirSaldoBRL();
                    break;
                default:
                    status_msg(false);
                    std::cout << "Saldo insuficiente para saque" << std::endl;
            }
        }
    }

    public:
        void exibirSaldoBTC() {
            std::cout << "BTC: " << btc << std::endl;
        }
        void exibirSaldoETH() {
            std::cout << "ETH: " << eth << std::endl;
        }
        void exibirSaldoBRL() {
            std::cout << "BRL: " << brl << std::endl;
        }
        void alterarSaldo() {

        }

};

int main () {

}