#include <iostream>

class Carteira {
    private:
        char endereco[51];
        float btc = 0, eth = 0, brl = 0;

    public:
        void exibirSaldo() {
            std::cout << "BTC: " << btc << " | ETH: " << eth << " | BRL: " << brl << "\n";
        }
        void alterar_Saldo(bool deposito) {
            int opcao;
            float valor;
            std::cout << "1 - Bitcoin | 2 - Ethereum | 3 - Reais\nEscolha: ";
            std::cin >> opcao;
            std::cout << "Valor: ";
            std::cin >> valor;

            if (valor <= 0){
                return;
            }
            if (deposito) {
                if (opcao == 1) {
                    btc += valor; 
                } 
                else if (opcao == 2) {
                    eth += valor;
                } 
                else if (opcao == 3) {
                    brl += valor;
                }
            } 
            else {
                if (opcao == 1) {
                    btc -= valor;
                } 
                else if (opcao == 2) {
                    eth -= valor;
                } 
                else if (opcao == 3) {
                    brl -= valor;
                }
            }
        }
};

int main() {
    Carteira usr1;
    
    usr1.exibirSaldo();
    std::cout << "1 - Sacar | 2 - Depositar\nEscolha: ";
    int opcao;
    std::cin >> opcao;

    // true para depositar false para sacar
    if (opcao == 1 || opcao == 2) { 
        if (opcao == 2) {
            usr1.alterar_Saldo(true); // depositar
        }
        else {
            usr1.alterar_Saldo(false); // sacar
        }
    }
}