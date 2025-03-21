#include <iostream>
using namespace std;

class linguagem_alienigena {
public:
    virtual void traduzir_mensagem() = 0;
    virtual bool validar() = 0;
    /*virtual bool validar() = 0;*/
    // esse destrutor virtual e sempre necessario quando trabalhado com polimorfismo
    // senao quando fizer delete mensagens[i] na main apenas o ponteiro para a classe 
    // linguagem_alienigena sera chamado, isso causara vazamento de memoria se a classe
    // derivada alocar recursos dinamicamente.
    virtual ~linguagem_alienigena() {}
};

class linguagem_zog : public linguagem_alienigena {
private:
    string msg;
public:
    linguagem_zog(const string &s) : msg(s) {}
    bool validar() override {
        return true;
    }
    void traduzir_mensagem() override {
        cout << msg << endl;
        cout << "Mensagem zog traduzida" << endl;
        if (validar()) {
            cout << "traducao valida" << endl;
        }
    }
};

class linguagem_xarn : public linguagem_alienigena {
private:
    string msg;
public:
    bool validar() override {
        return true;
    }
    linguagem_xarn(const string &s) : msg(s) {}
    void traduzir_mensagem() override {
        cout << msg << endl;
        cout << "Mensagem xarn traduzida" << endl;
        if (validar()) {
            cout << "traducao valida" << endl;
        }
    }
};

// array de ponteiros para objetos de classes derivadas em C++ usando polimorfismo
int main() {
    linguagem_alienigena* mensagens[] = {
        new linguagem_zog("Zyq'lor Vekthuun!"),
        new linguagem_xarn("BEM LEGAL SUA COLOCACAO"),
        new linguagem_zog("Guerra dos mundos"),
        new linguagem_zog("Nao sei oq digitar"),
        new linguagem_xarn("Busquem conhecimento")
    };

    for (int i = 0; i < 5; i++) {
        mensagens[i] -> traduzir_mensagem();
        delete mensagens[i];
        cout << "~mensagem[" << i << "]" << endl;
    }

    return 0;
}
