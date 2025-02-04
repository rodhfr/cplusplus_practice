#include <iostream>
#include <string>

/* 1. Crie uma classe Carteira com os seguintes atributos:
endereco (char[50])
saldo_btc (float)
saldo_eth (float)
saldo_brl (float)
*/


class Carteira {
    private:
        char endereco[51];
        float saldo_btc = 500;
        float saldo_eth = 600;
        float saldo_brl = 700;

        int selectWalletMenu(){
            int opt;
            while (true) {
                std::cout << "Selecione a Carteira:" << std::endl;
                std::cout << "(1) Bitcoin" << std::endl;
                std::cout << "(2) Ethereum" << std::endl;
                std::cout << "(3) Reais" << std::endl;
                std::cin >> opt;

                // copiei da internet o snippet a seguir pois se o input nao for numerico fica com loop infinito do else. Pesquisar pra ver se implemento
                // if (std::cin.fail()) {  
                //     std::cin.clear();  
                //     std::cin.ignore(10000, '\n');  
                //     std::cout << "Entrada invalida! Digite um numero entre 1 e 3." << std::endl;
                //     continue;  
                // }
                if (opt >= 1 && opt <= 3){
                    return opt;
                }
                std::cout << "Opcao invalida! Repita a operacao" << std::endl;
            };
        };
        
        void sacar(){
            int opt, usr_confirmation;
            float v_saque;
            std::cout << "-- Menu de Saque --" << std::endl;
            /* 
            Funcao selectWalletMenu mostra no console as opcoes de fundos de investimento e retorna o codigo do fundo
            IDs: 
            1 - Bitcoin
            2 - Ethereum
            3 - Reais
            */
            opt = selectWalletMenu();
            switch (opt){
                case 1:
                    std::cout << "Insira o valor para o saque de Bitcoin:" << std::endl;
                    std::cin >> v_saque;
                    std::cout << "(1) Confirmar Saque" << std::endl << "(2) Cancelar e Voltar ao Menu Principal" << std::endl;
                    std::cin >> usr_confirmation;
                    if (usr_confirmation == 1){
                        if (saldo_btc >= v_saque && saldo_btc > 0){
                            saldo_btc -= v_saque;
                        }
                        else{
                            std::cout << "Saldo Insuficiente." << std::endl;
                        }
                        break;
                    }
                    else {
                        return;
                    }

                case 2:
                    std::cout << "Insira o valor para o saque de Ethereum:" << std::endl;
                    std::cin >> v_saque;
                    std::cout << "(1) Confirmar Saque" << std::endl << "(2) Cancelar e Voltar ao Menu Principal" << std::endl;
                    std::cin >> usr_confirmation;
                    if (usr_confirmation == 1) {
                        if (saldo_eth >= v_saque && saldo_eth > 0){
                            saldo_eth -= v_saque;
                        }
                        else{
                            std::cout << "Saldo Insuficiente." << std::endl;
                        };
                        break;
                    }
                    else {
                        return;
                    }

                case 3:
                    std::cout << "Insira o valor para o saque de Reais:" << std::endl;
                    std::cin >> v_saque;
                    std::cout << "(1) Confirmar Saque" << std::endl << "(2) Cancelar e Voltar ao Menu Principal" << std::endl;
                    std::cin >> usr_confirmation;
                    if (usr_confirmation == 1){
                        if (saldo_brl >= v_saque && saldo_brl > 0){
                            saldo_brl -= v_saque;
                        }
                        else{
                            std::cout << "Saldo Insuficiente." << std::endl;
                        };
                        break;
                    }
                    else{
                        return;
                    }
            }
        };

        void deposito(){
            int opt;
            float v_dep;
            std::cout << "-- Menu de Deposito --" << std::endl;
            /* 
            Funcao selectWalletMenu mostra no console as opcoes de fundos de investimento e retorna o codigo do fundo
            IDs: 
            1 - Bitcoin
            2 - Ethereum
            3 - Reais
            */
            opt = selectWalletMenu();
            switch (opt){
                case 1:
                    std::cout << "Insira o valor para o deposito de bitcoin" << std::endl;
                    std::cin >> v_dep;
                    if (v_dep >= 1) {
                        saldo_btc += v_dep;
                        break;
                    }
                    else {
                        std::cout << "Valor de Deposito Invalido" << std::endl;
                    }
                case 2:
                    std::cout << "Insira o valor para o deposito de Ethereum" << std::endl;
                    std::cin >> v_dep;
                    saldo_eth += v_dep;
                    break;
                case 3:
                    std::cout << "Insira o valor para o deposito de Reais" << std::endl;
                    std::cin >> v_dep;
                    saldo_brl += v_dep;
                    break;
            };
        };

        
    public:

        void alterar_saldo(){
            int op_opt, opt;
            while (true) {
                std::cout << "-- Menu de Operacoes --" << std::endl;
                std::cout << "(1) Sacar" << std::endl;
                std::cout << "(2) Depositar" << std::endl;
                std::cin >> op_opt;
                switch (op_opt) {
                    case 1:
                        sacar();
                        return;                
                    case 2:
                        deposito();
                        return;
                    default:
                        std::cout << "Opcao invalida! Repita a operacao" << std::endl;
                }
            }
        }
        void exibir_saldo(){
            int opt;
            opt = selectWalletMenu();
            switch (opt) {
                case 1:
                    std::cout << "Saldo Bitcoin:" << saldo_btc << "BTC" << std::endl;
                    break;
                case 2:
                    std::cout << "Saldo Ethereum:" << saldo_eth << "ETH" << std::endl;
                    break;
                case 3:
                    std::cout << "Saldo Real:" << saldo_brl << "R$" << std::endl;
                    break;
                default:
                    std::cout << "Opcao invalida! Repita a operacao" << std::endl;
            };
        };
};

int main (){
    Carteira usr;
    
    usr.exibir_saldo();
    

    return 0;
}
