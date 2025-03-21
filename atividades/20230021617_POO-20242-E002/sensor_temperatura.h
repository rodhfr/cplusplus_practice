#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include "utils.h" // write-read logs, sleep e time
#include "dispositivo_industrial.h" // classe base de sensor_temperatura
#include <iostream>

using namespace std;

class sensor_temperatura : public dispositivo_industrial {
private:
    double temperatura_maxima;
    double temperatura_minima;
    double temp_atual = getTemperatura();
    bool status = getStatus();
    string relatorio;
public:
    bool alerta_temperatura() { // return true if temp fora dos limites aceitaveis
        string stcodegreen, stcodered, stcodeblue;
        if (temp_atual > temperatura_minima && temp_atual < temperatura_maxima) {
            stcodegreen = "Temperatura normal...";
            cout << stcodegreen << endl;
            relatorio += stcodegreen;
            return false;
        }
        else if (temp_atual > temperatura_maxima) { 
            stcodered = "PERIGO: ALTA TEMPERATURA!";
            cout << stcodered << endl; 
            relatorio += stcodered;
            return true;
        }
        else {
            stcodeblue = "Temperatura abaixo da requerida para funcionamento"
            relatorio += stcodeblue;
            cout << stcodeblue << endl;
            return true;
        }
    }
    void iniciar() override {
        void setStatus(true);
        while (status) {
            cout << "dispositivo_industrial::sensor_temperatura status is true rodando maquina..." << endl;
            alerta_temperatura();
            cout << "esperando 1000ms" << endl;
            sleep(1);
        }
    }
    void parar() override {
        void setStatus(false);
    }
    string gerar_relatorio() override {
        escreverLog(relatorio, "temperatura")
    }

    /*TODO: implementar os seguintes polimorfismos:*/
    /*      iniciar(): ativa o sensor de temp e inicia leitura*/
    /*      parar(): desativa sensor*/
    /*      gerar_relatorio(): fornece relatorio com valores da temperatura atual, minima e maxima*/

};
#endif // SENSOR_TEMPERATURA_H
