/*3. Write a C++ program to create a class called Person that has private member variables for name, age and country. Implement member functions to set and get the values of these variables.*/

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    string country;
public:
    void setName(const string& new_name){
        name = new_name;
    }
    void setAge(const int new_age){
        age = new_age;
    }
    void setCountry(const string& new_country){
        country = new_country;
    }
    string getName() {
        cout << "Name: ";
        return name;
    }
    int getAge() {
        cout << "Age: ";
        return age;
    }
    string getCountry() {
        cout << "Country: ";
        return country;
    }
};

int main() {
    Person person1;
    person1.setName("Eduardo");
    person1.setAge(22);
    person1.setCountry("Uganda");
    cout << "-- Dados Pessoais -- " << endl;
    cout << person1.getName() << endl;
    cout << person1.getCountry() << endl;
    cout << person1.getAge() << endl;
    return 0;
}
