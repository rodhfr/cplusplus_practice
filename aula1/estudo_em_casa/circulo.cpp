#include <iostream>
#include <iomanip>

// A = pi . area ^ 2

int main(){
    float raio, area;
    float pi = 3.14159265;

    // input
    std::cout << "Digite o raio do circulo: " << std::endl;
    std::cin >> raio;
    std::cout << "Raio digitado foi: " << raio << std::endl;

    // calculo area
    area = pi * (raio * raio);

    // output
    std::cout << "A area do circulo de raio " 
        << raio 
        << " tem area de: " 
        << std::fixed
        << std::setprecision(2)
        << area 
        << std::endl;
    std::cout << "A area com mais precisao: "
        << area 
        << std::fixed
        << std::setprecision(2)
        << std::endl;

            


    return 0;
    
}
