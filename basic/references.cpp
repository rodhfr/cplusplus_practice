#include <iostream>
#include <string>
using namespace std;

int main() {
/* 
uma variavel de referencia e uma referencia para uma variavel existente
criada com o operador & 
*/
    string food = "Pizza";
    string &meal = food;

    cout << "Printando meal " << endl;
    cout << meal << endl;
    cout << "Printando food " << endl;
    cout << food << endl;


// e possivel resgatar o endereco de memoria de uma variavel
   string animal = "Cat";
   cout << "Memory address where cat is located " << endl;
   cout << &food << endl;


    return 0;
}    
