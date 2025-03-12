/*4. Write a C++ program to create a class called Car that has private member variables for company, model, and year. Implement member functions to get and set these variables.*/

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string company;
    string model;
    int year;
public:
    void setCompany(const string& c){
        company = c;
    }
    void setModel(const string& m){
        model = m;
    }
    void setYear(int y){
        year = y;
    }
    string getCompany(){
        return company;
    }
    string getModel(){
        return model;
    }
    int getYear(){
        return year;
    }
};

int main() {
    Car carro1;
    carro1.setCompany("BMW");
    carro1.setModel("X12");
    carro1.setYear(2015);

    cout << "Company: " << carro1.getCompany() << endl << "Model: " << carro1.getModel() << endl << "Year: " << carro1.getYear() << endl;

    return 0;
}
