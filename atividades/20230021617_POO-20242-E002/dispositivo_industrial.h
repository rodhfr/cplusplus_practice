#ifndef DISPOSITIVO_INDUSTRIAL_H
#define DISPOSITIVO_INDUSTRIAL_H

#include <iostream>
#include <string>

using namespace std;

class dispositivo_industrial {
private:
    string id;
    bool status;
    double temperatura;
public:
        // TODO: metodo virtual de verificar_seguranca()
        virtual bool verificar_seguranca() { 
            return true; // retorna booleano verificando se esta operando em condicoes seguras 
        }; 
        virtual void iniciar() = 0; // coloca o dispositivo em funcionamento
        virtual void parar() = 0; // interrompe funcionamento do dispositivo
        virtual string gerar_relatorio() = 0; // retorna string com info sobre o estado atual do dispositivo
        virtual ~dispositivo_industrial() {
            cout << "destrutor virtual ~dispositivo_industrial chamado" << endl;
        }
        // Getters
        string getId() const { return id; }
        bool getStatus() const { return status; }
        double getTemperatura() const { return temperatura; }
        // Setters
        void setId(string i) { id = i; }
        void setStatus(bool s) { status = s; }
        void setTemperatura(double t) { temperatura = t; }
};

#endif // DISPOSITIVO_INDUSTRIAL_H
