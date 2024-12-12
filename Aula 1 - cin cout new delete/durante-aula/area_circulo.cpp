#include <iostream>
#include <iomanip>
using namespace std;


int main (void){

    float raio, area;
    std::cout << "digite a area do circulo: ";
    std::cin >> raio;

    cout << "Raio Inserido: " << std::setprecision(2) << raio << endl;

    float pi = 3.14;
    area = pi * (raio * raio);

    cout << "Raio do Circulo: ";
    cout << fixed << setprecision(2) << area << endl;

    return 0;
}


// calculo da area do ciculo e exibab a area com 2 e 6 casas decimais
// A = pi . r ^ 2

