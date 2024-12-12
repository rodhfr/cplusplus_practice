#include <iostream>
#include <ostream>

int main (){
    int numeros[6];
    std::cout << "Digite tres numeros inteiros: " << std::endl;
    std::cin >> numeros[0];
    std::cout << "Seu numero digitado foi "<< numeros[0] << std::endl;

    for (int i = 0; i < 5; i++){
        std::cout << "Digite o" << i << "o numero" << std::endl;
        std::cin >> numeros[i];
    }

    for (int i = 0; i < 5; i++){
         std::cout << "loop iteracao" << i << std::endl;
    }
    

}

