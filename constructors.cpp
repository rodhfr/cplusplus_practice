#include <iostream>
#include <string>
using namespace std;

/*
Construtor é um método especial que é chamado automaticamente
quando um objeto de uma classe é criado.
Sua síntaxe é definida por ser homônicidade à classe, seguido
de parêntesis com possíveis parâmetros.
*/

class Car {
public:
    string model;
    string brand;
    int year;

    // Constructor. declaration outside scope
    Car(string x, string y, int z);

};

Car::Car(string x, string y, int z) {
    brand = x;
    model = y;
    year = z;
}


int main () {
    Car obj1("BMW", "X5", 1997);

}