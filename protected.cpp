/*
Arquivo: protected.cpp
Descrição: Como funciona o especificador de acesso protected em C++.
Autor: Rodolfo França de Souza
Data: 20/02/2025
*/

#include <iostream>
#include <string>
using namespace std;

/*
Descrição do programa:
O protected pode ser utilizado para acessar atributos somente nas classes herdadas.
Conceitos abordados:
- Especificador de acesso protected
*/

class Employee {
protected:
    int salary;
};

class Programmer: public Employee {
public:
    int bonus;
    void setSalary(int s) {
        salary = s;
    }
    int getSalary() {
        return salary;
    }
};

int main() {
    Programmer myObj;
    myObj.setSalary(50000);
    myObj.bonus = 15000;
    cout << "Salary: " << myObj.getSalary() << endl;
    cout << "Bonus: " << myObj.bonus << endl;

    return 0;
}