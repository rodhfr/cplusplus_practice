#include <iostream>
#include <string>
using namespace std;

// default parameter value
void myFunction(string country = "Brazil") {
    cout << country << endl;
}

void trocaNums(int &primeiro, int &segundo) {
    int z = primeiro;
    primeiro = segundo;
    segundo = z;
}

void myFuncArray(int arrayNumeros[5]) {
    // Essa função recebe como parametro um array de 5 números
    // e printa cada um dos índices até 5.
    for (int i = 0; i < 5; i++) {
        cout << arrayNumeros[i] << endl;
    }
}


int main() {
    myFunction("Suecia");
    myFunction();


    // Passando parametros por referência
    int firstNum = 10;
    int secondNum = 15;

    cout << "Antes da troca: " << endl;
    cout << firstNum << endl << secondNum << endl;

    trocaNums(firstNum, secondNum);

    cout << "Depois da troca: " << endl;
    cout << firstNum << endl << secondNum << endl;


    // Passando arrays como parâmetro de função
    cout << "Passando array como parameter de func" << endl;
    int myArray[5] = {10, 20, 30, 40, 50};
    myFuncArray(myArray);

    return 0;
}
