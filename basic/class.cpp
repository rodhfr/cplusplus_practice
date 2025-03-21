#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    int year;
    string brand;
    string model;

public:
// Métodos são funções que pertencem a classes;
    void sayHello() {
        cout << "Hello, World!" << endl;
    }

};

int main() {
    Car carObj1;
    carObj1.sayHello();
    
    
    return 0;
}
