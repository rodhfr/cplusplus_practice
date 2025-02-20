#include <iostream>
#include <string>
using namespace std;

int main() {
/*
O ponteiro é uma variável que guarda um endereço de memória como seu valor.
Apontando para dados do mesmo tipo.
Criado com o operador *.
O endereço da variável em trabalho é associada ao ponteiro.
*/
    string animal = "Cat";
    string* ptr = &animal;

    std::cout << "animal:" << std::endl;
    cout << animal << endl;

    cout << "&animal: " << endl;
    cout << &animal << endl;

    cout << "ptr: " << endl;
    cout << ptr << endl;

    string food = "Hot Dogz";
    cout << "food: " << endl;
    cout << food << endl;

    // ponteiro food
    string* ptrfood = &food;

    cout << "ptrfood (endereco): " << endl;
    cout << ptrfood << endl;

    cout << "ptrfood (valor): " << endl;
    cout << *ptrfood << endl;
/*
Modificando ponteiros
*/
    cout << "-- Modificando valor dos ponteiros --" << endl;

    string carro = "Mercedes";
    string* ptrcarro = &carro;

    cout << "carro: " << endl; 
    cout << carro << endl;

    cout << "&food: " << endl; 
    cout << &food << endl;

    cout << "*ptrcarro: " << endl;
    cout << *ptrcarro << endl;
    
    // mudando o valor do ponteiro
    *ptr = "Subaru";
    cout << "*ptrcarro: " << endl;
    cout << *ptrcarro << endl;

    cout << "carro: " << endl; 
    cout << carro << endl;

    return 0;
}
