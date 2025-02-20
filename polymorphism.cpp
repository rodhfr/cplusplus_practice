/*
Arquivo: polymorphism.cpp
Descrição: O que é polimorfismo em C++.
Autor: Rodolfo França de Souza
Data: 02/20/2025
*/

#include <iostream>
#include <string>
using namespace std;

/*
Descrição do programa:
O Polimorfismo acontece quando temos muitas classes que se relacionam uma com as outras por herança.
Enquanto a heraça permite herdar atributos e métodos de outra classe, o Polimorfismo usa esses métodos
para performar tarefas diferentes. Isso permite exercer uma única ação de formas diferentes.

Conceitos abordados:
Sobrescrever um método em uma classe herdeira para chamá-lo com o mesmo nome e ter uma função diferente.
*/

class Animal {
public:
    void animalSound() {
        cout << "The animal makes a sound " << endl;
    }
};

class Pig: public Animal {
public:
    void animalSound() {
        cout << "The pig says: Oinc! Oinc!" << endl;
    }
};

class Dog: public Animal {
public:
    void animalSound() {
        cout << "The dog says: Ruf Ruf" << endl;
    }
};


int main() {
    Animal myAnimal;
    Pig myPig;
    Dog myDog;

    myAnimal.animalSound();
    myPig.animalSound();
    myDog.animalSound();
    

           
    return 0;
}
