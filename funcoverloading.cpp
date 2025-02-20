#include <iostream>
#include <string>
using namespace std;

/*
Sobrecarga de função é quando multiplas funções podem ter o mesmo nome
mas apresentarem parâmetros diferentes (tipos)*/

int sum(int a, int b) {
    // return sum of a + b int parameters;
    return a + b;
}

double sum(double a, double b) {
    // return sum of a + b double parameters;
    return a + b;
}

int main() {
    
    int myNum1 = sum(8, 5);
    double myNum2 = sum(4.3, 6.26);
    cout << "Int: " << myNum1 << "\n";
    cout << "Double: " << myNum2;
    
    
    return 0;
}
