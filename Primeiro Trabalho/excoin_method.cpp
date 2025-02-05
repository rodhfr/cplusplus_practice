#include <iostream>

class Carteira {
    private:
    char endereco[51];
    float btc = 0, eth = 0, brl = 0;

    void deposito(float quantia, int carteira_id) {
        if (quantia > 0) {
            switch (carteira_id){
                case 1:
                    btc  += valor;
                case 2:
                    eth += valor;
                case 3:
                    brl += valor;
            }
        }
        else {
            return;
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
        void alterarSaldo(){

        }

}