#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>

using std::ofstream;
using std::ifstream;
using std::string;
using std::cerr;
using std::cout;
using std::endl;

void escreverLog(const string& mensagem, const string& filename) {
    string filenametxt = filename + ".txt";
    ofstream arquivo(filenametxt);
    if (arquivo.is_open()) {
        arquivo << mensagem;
        arquivo.close();
        cout << "Log escrito com sucesso em " << filenametxt << endl;
    }
    else { 
        cerr << "Erro ao escrever o arquivo " << filenametxt << endl;
    }
}

void lerLog(const string& filename) { 
    string filenametxt = filename + ".txt";
    ifstream arquivo(filenametxt);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filenametxt << endl;
        return;
    }
    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }
    arquivo.close();
}

/*int main() {*/
/*    escreverLog("mensagem de exemplo apenas demonstrativa blabla", "exemplo");*/
/*    lerLog("exemplo");*/
/*    return 0;*/
/*}*/
