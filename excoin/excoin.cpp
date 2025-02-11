#include <iostream>
using namespace std;

class Carteira {
private:
    char* endereco;
    float saldo_btc, saldo_eth, saldo_brl;
public:
    Carteira(const char* end, float btc = 0.0f, float eth = 0.0f, float brl = 0.0f) {
        int i = 0;
        endereco = new char[50];
        while(end[i] != '\0' && i < 49) {
            endereco[i] = end[i];
            i++;
        }
        endereco[i] = '\0';
        saldo_btc = btc;
        saldo_eth = eth;
        saldo_brl = brl;
    }
    
    ~Carteira() {
        delete[] endereco;
    }
    
    void depositoBTC(float quant) {
        if (quant >= 0) {
            saldo_btc += quant;
            cout << "Deposito BTC realizado" << endl;
        } else {
            cout << "Erro no deposito BTC" << endl;
        }
    }
    void depositoETH(float quant) {
        if (quant >= 0) {
            saldo_eth += quant;
            cout << "Deposito ETH realizado" << endl;
        } else {
            cout << "Erro no deposito ETH" << endl;
        }
    }
    void depositoBRL(float quant) {
        if (quant >= 0) {
            saldo_brl += quant;
            cout << "Deposito BRL realizado" << endl;
        } else {
            cout << "Erro no deposito BRL" << endl;
        }
    }
    
    void saqueBTC(float quant) {
        if (quant > 0 && saldo_btc >= quant) {
            saldo_btc -= quant;
            cout << "Saque BTC realizado" << endl;
        } else {
            cout << "Erro: saldo BTC insuficiente ou valor invalido" << endl;
        }
    }
    void saqueETH(float quant) {
        if (quant > 0 && saldo_eth >= quant) {
            saldo_eth -= quant;
            cout << "Saque ETH realizado" << endl;
        } else {
            cout << "Erro: saldo ETH insuficiente ou valor invalido" << endl;
        }
    }
    void saqueBRL(float quant) {
        if (quant > 0 && saldo_brl >= quant) {
            saldo_brl -= quant;
            cout << "Saque BRL realizado" << endl;
        } else {
            cout << "Erro: saldo BRL insuficiente ou valor invalido" << endl;
        }
    }
    
    float get_saldo_btc() { return saldo_btc; }
    float get_saldo_eth() { return saldo_eth; }
    float get_saldo_brl() { return saldo_brl; }
    
    void exibir_saldo() {
        cout << "Endereco: " << endereco << endl;
        cout << "BTC: " << saldo_btc << endl;
        cout << "ETH: " << saldo_eth << endl;
        cout << "BRL: " << saldo_brl << endl;
    }
};

// COMPRA: carteira origem compra (com brl) e carteira destino vende cripto
// VENDA: carteira origem vende cripto e carteira destino compra com brl 
class Transacao {
private:
    char* tipo; 
    int moedac1, moedac2; // brl: 500, 600: btc, 700: eth.
    float quantidade;
    float preco_unitarioBTC;  // 1 BTC = 50.000 BRL
    float preco_unitarioETH;  // 1 ETH = 1.500 BRL
    float preco_unitarioBRL;  // BRL = 1 (moeda de troca tb)
    Carteira* carteira_origem;
    Carteira* carteira_destino;
    
    // mapear string para codigo da moeda
    int mapear_moeda(const char* m) {
        if(m[0]=='B' && m[1]=='R' && m[2]=='L' && m[3]=='\0')
            return 500;
        if(m[0]=='B' && m[1]=='T' && m[2]=='C' && m[3]=='\0')
            return 600;
        if(m[0]=='E' && m[1]=='T' && m[2]=='H' && m[3]=='\0')
            return 700;
        return -1;
    }
    
public:
    Transacao(const char* t, const char* m, float q, Carteira* origem, Carteira* destino) {
        quantidade = q;
        carteira_origem = origem;
        carteira_destino = destino;
        
        preco_unitarioBTC = 50000.0f;
        preco_unitarioETH = 1500.0f;
        preco_unitarioBRL = 1.0f;
        
        // alocando a string de tipo
        int i = 0;
        tipo = new char[20];
        while(t[i] != '\0' && i < 19) {
            tipo[i] = t[i];
            i++;
        }
        tipo[i] = '\0';
        
        // Compra usa brl para comprar cripto
        // venda vende cripto e recebe brl
        if(tipo[0]=='C') { // COMPRA
            moedac1 = 500;              // Usa BRL para comprar
            moedac2 = mapear_moeda(m);    // Cripto a ser comprada
        } else if(tipo[0]=='V') { // VENDA
            moedac1 = mapear_moeda(m);   // Cripto a ser vendida
            moedac2 = 500;               // Recebe BRL
        } else {
            // erro 
            moedac1 = 0;
            moedac2 = 0;
        }
        
        // mostrar operacao no console
        if(tipo[0]=='C')
            cout << "Tipo de transacao: COMPRA" << endl;
        else if(tipo[0]=='V')
            cout << "Tipo de transacao: VENDA" << endl;
        else
            cout << "Erro: Tipo de transacao invalido!" << endl;
    }
    
    ~Transacao() {
        delete[] tipo;
    }
    
    void executar_transacao() {
        if(tipo[0]=='C') {  // compra
            if(moedac2 == 600) { // compra de BTC
                float custo = quantidade * preco_unitarioBTC;
                if(carteira_origem->get_saldo_brl() >= custo && carteira_destino->get_saldo_btc() >= quantidade) {
                    carteira_origem->saqueBRL(custo);
                    carteira_origem->depositoBTC(quantidade);
                    carteira_destino->saqueBTC(quantidade);
                    carteira_destino->depositoBRL(custo);
                    cout << "Compra de " << quantidade << " BTC realizada!" << endl;
                } else {
                    cout << "Transacao COMPRA de BTC falhou: saldo insuficiente." << endl;
                }
            } else if(moedac2 == 700) { // compra de ETH
                float custo = quantidade * preco_unitarioETH;
                if(carteira_origem->get_saldo_brl() >= custo && carteira_destino->get_saldo_eth() >= quantidade) {
                    carteira_origem->saqueBRL(custo);
                    carteira_origem->depositoETH(quantidade);
                    carteira_destino->saqueETH(quantidade);
                    carteira_destino->depositoBRL(custo);
                    cout << "Compra de " << quantidade << " ETH realizada!" << endl;
                } else {
                    cout << "Transacao COMPRA de ETH falhou: saldo insuficiente." << endl;
                }
            } else {
                cout << "Moeda invalida para COMPRA." << endl;
            }
        } else if(tipo[0]=='V') {  // venda
            if(moedac1 == 600) { // venda de BTC
                float valor_recebido = quantidade * preco_unitarioBTC;
                if(carteira_origem->get_saldo_btc() >= quantidade && carteira_destino->get_saldo_brl() >= valor_recebido) {
                    carteira_origem->saqueBTC(quantidade);
                    carteira_origem->depositoBRL(valor_recebido);
                    carteira_destino->saqueBRL(valor_recebido);
                    carteira_destino->depositoBTC(quantidade);
                    cout << "Venda de " << quantidade << " BTC realizada!" << endl;
                } else {
                    cout << "Transacao VENDA de BTC falhou: saldo insuficiente." << endl;
                }
            } else if(moedac1 == 700) { // venda de ETH
                float valor_recebido = quantidade * preco_unitarioETH;
                if(carteira_origem->get_saldo_eth() >= quantidade && carteira_destino->get_saldo_brl() >= valor_recebido) {
                    carteira_origem->saqueETH(quantidade);
                    carteira_origem->depositoBRL(valor_recebido);
                    carteira_destino->saqueBRL(valor_recebido);
                    carteira_destino->depositoETH(quantidade);
                    cout << "Venda de " << quantidade << " ETH realizada!" << endl;
                } else {
                    cout << "Transacao VENDA de ETH falhou: saldo insuficiente." << endl;
                }
            } else {
                cout << "Moeda invalida para VENDA." << endl;
            }
        } else {
            cout << "Tipo de transacao invalido." << endl;
        }
    }
    
    void exibir_detalhes() {
        cout << "=== Detalhes da Transacao ===" << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Moeda de origem: ";
        if(moedac1 == 500) cout << "BRL";
        else if(moedac1 == 600) cout << "BTC";
        else if(moedac1 == 700) cout << "ETH";
        else cout << "Desconhecido";
        cout << endl;
        cout << "Moeda de destino: ";
        if(moedac2 == 500) cout << "BRL";
        else if(moedac2 == 600) cout << "BTC";
        else if(moedac2 == 700) cout << "ETH";
        else cout << "Desconhecido";
        cout << endl;
        cout << "=============================" << endl;
    }
};

class Exchange {
private:
    Carteira** carteiras;
    int num_carteiras;
    Transacao** transacoes;
    int num_transacoes;
public:
    Exchange() {
        carteiras = 0;
        num_carteiras = 0;
        transacoes = 0;
        num_transacoes = 0;
    }
    
    ~Exchange() {
        if(carteiras != 0)
            delete[] carteiras;
        for (int i = 0; i < num_transacoes; i++) {
            delete transacoes[i];
        }
        if(transacoes != 0)
            delete[] transacoes;
    }
    
    void adicionar_carteira(Carteira* c) {
        // verificar se a carteira ja foi criada (nao muito testado)
        //for (int i = 0; i < num_carteiras; i++) {
        //    if (carteiras[i] == c) {
        //        cout << "Erro: Carteira ja cadastrada!" << endl;
        //        return;
        //    }
        //}
        Carteira** temp = new Carteira*[num_carteiras + 1];
        for (int i = 0; i < num_carteiras; i++) {
            temp[i] = carteiras[i];
        }
        temp[num_carteiras] = c;
        if(carteiras != 0)
            delete[] carteiras;
        carteiras = temp;
        num_carteiras++;
    }
    
    void exibir_carteiras() {
        cout << "=== Carteiras na Exchange ===" << endl;
        for (int i = 0; i < num_carteiras; i++) {
            carteiras[i]->exibir_saldo();
            cout << "-----------------------------" << endl;
        }
    }
    
    void realizar_transacao(const char* tipo, const char* moeda, float quantidade, Carteira* origem, Carteira* destino) {
        Transacao* nova_transacao = new Transacao(tipo, moeda, quantidade, origem, destino);
        nova_transacao->executar_transacao();
        
        Transacao** temp = new Transacao*[num_transacoes + 1];
        for (int i = 0; i < num_transacoes; i++) {
            temp[i] = transacoes[i];
        }
        temp[num_transacoes] = nova_transacao;
        if(transacoes != 0)
            delete[] transacoes;
        transacoes = temp;
        num_transacoes++;
    }
};

int main(){
    cout << "######################" << endl;
    cout << "####### Excoin #######" << endl;
    cout << "######################" << endl;
    cout << endl;
    cout << "Criando carteiras..." << endl;
    
    Exchange exchange;
    // criacao de carteiras
    Carteira carteira1("endereco1", 1.5f, 2.0f, 50000.0f);
    Carteira carteira2("endereco2", 0.8f, 3.5f, 20000.0f);
    Carteira carteira3("endereco3", 0.2f, 1.0f, 60000.0f);
    // add carteiras atraves da exchange
    exchange.adicionar_carteira(&carteira1);
    exchange.adicionar_carteira(&carteira2);
    exchange.adicionar_carteira(&carteira3);
    
    cout << "Exibindo estado inicial das carteiras:" << endl;
    exchange.exibir_carteiras();
    cout << "====================================" << endl;
    
    cout << "Executando transacoes..." << endl;
    
    // Caso 1: Compra bem-sucedida de BTC
    // Carteira3 (compradora) compra 0.1 BTC da Carteira1 (vendedora).
    cout << "Caso 1: Compra de 0.1 BTC, carteira3 (compradora) compra de carteira1 (vendedora)" << endl;
    exchange.realizar_transacao("COMPRA", "BTC", 0.1f, &carteira3, &carteira1);
    cout << "====================================" << endl << endl;
    
    // Caso 2: Venda bem-sucedida de ETH
    // Carteira2 (vendedora) vende 1 ETH para Carteira3 (compradora).
    cout << "Caso 2: Venda de 1 ETH, carteira2 (vendedora) vende para carteira3 (compradora)" << endl;
    exchange.realizar_transacao("VENDA", "ETH", 1.0f, &carteira2, &carteira3);
    cout << "====================================" << endl << endl;
    
    // Caso 3: Tentativa de compra com saldo insuficiente.
    // Carteira1 (compradora) tenta comprar 2 BTC da Carteira2 (vendedora).
    cout << "Caso 3: Tentativa de compra de 2 BTC, carteira1 (compradora) tenta comprar de carteira2 (vendedora)" << endl;
    exchange.realizar_transacao("COMPRA", "BTC", 2.0f, &carteira1, &carteira2);
    cout << "====================================" << endl << endl;
    
    // Caso 4: Tentativa de venda com quantidade superior ao disponível.
    // Carteira3 (vendedora) tenta vender 5 ETH para Carteira2 (compradora).
    cout << "Caso 4: Tentativa de venda de 5 ETH, carteira3 (vendedora) tenta vender para carteira2 (compradora)" << endl;
    exchange.realizar_transacao("VENDA", "ETH", 5.0f, &carteira3, &carteira2);
    cout << "====================================" << endl << endl;
    
    cout << "Exibindo estado final das carteiras:" << endl;
    exchange.exibir_carteiras();
    
    return 0;
}
