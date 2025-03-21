#include <iostream>
#include <string>
using namespace std;

/*
Encapsulation
Na encapsulação, dados sensíveis são escondidos do usuário declarando atributos de
classe como privados. Podendo ser dado o acesso de leitura e escrita através de méto-
dos de get e set.

Especificadores de Acesso:
public - membros acessíveis por fora da classe.
private - membros não podem ser acessíveis or vistos fora da classe
protected - membros não podem ser acessados fora da classe, mas podem ser acessados
em classes herdadas.*/

class Employee {
private:
    // private attributes
    int salary;
public:
    // setters
    void setSalary(int s) { salary = s; }
    // getters
    int getSalary() { return salary; }
protected:


};



int main() {
    Employee myObj;
    myObj.setSalary(50000);
    cout << myObj.getSalary() << endl;
    
    
    return 0;
}
