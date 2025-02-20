#include <iostream>
#include <string>
using namespace std;

/*
Para definir um método fora da definição da classe 
será necessário na declaração da função, 
especificar o nome da classe. Isso é feito colocando 
o nome da classe, um operador de resolução de escopo, 
seguido do nome do metodo. 

void MyClass::myMethod() {}

*/

class Car {
private:
    string model;
    public:
    // setters
    void setModel(const string& m) { model = m; }
    // getters
    string getModel() const { return model; }

    void myMethod();
};

// Função fora do escopo da classe:
void Car::myMethod() {
    cout << "Hello, World! " << endl;
}



int main() {
    Car carObj1;
    carObj1.setModel("z11");
    carObj1.getModel();
    carObj1.myMethod();
    
    std::cout << "Welcome!" << std::endl;
    
    
    
    
    return 0;
}
