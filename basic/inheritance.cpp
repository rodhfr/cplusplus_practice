#include <iostream>
#include <string>
using namespace std;

/*
Arquivo: inheritance.cpp
Descrição: Demonstração de herança em C++ (simples, multinível e múltipla).
Autor: Rodolfo França de Souza
Data: 20/02/2025

Conceitos abordados:
- Herança (classe base e derivada)
- Herança multinível (cadeia de herança)
- Herança múltipla (herança de múltiplas classes)
*/

/* 
Classe base: Vehicle 
Descrição: Classe base que representa um veículo genérico.
Possui um atributo 'brand' e um método 'honk()'.
*/
class Vehicle {
public:
    string brand = "Ford"; // Marca do veículo
    void honk() { // Método para buzinar
        cout << "Tuut, tuut!" << endl;
    }
};

/* 
Classe derivada: Car 
Descrição: Classe que herda de 'Vehicle' e adiciona um atributo 'model'.
*/
class Car : public Vehicle {
public:
    string model = "Mustang"; // Modelo do carro
};

/* 
Herança multinível: myClass -> myChildClass -> myGrandChildClass
Descrição: Demonstra a herança em múltiplos níveis, onde cada classe 
herda da anterior.
*/
class myClass {
public:
    void consoleOut() {
        cout << "some output in parent class" << endl;
    }
};
class myChildClass : public myClass {}; // Herda de myClass
class myGrandChildClass : public myChildClass {}; // Herda de myChildClass

/*
Herança multipla: myGrandChildClass que herda de Vehicle e myClass
Descrição: a uma classe pode herdar atributos e métodos de outras classes que não estão encadeadas.
*/
class mygrandChildClass: public Vehicle, public myClass {};

int main() {
    // Exemplo de herança simples
    Car myCar;
    myCar.honk();
    cout << myCar.brand + " " + myCar.model << endl;
    
    // Exemplo de herança multinível
    myGrandChildClass obj1;
    obj1.consoleOut();

    return 0;
}
