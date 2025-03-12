/*7. Write a C++ program to implement a class called Employee that has private member variables for name, employee ID, and salary. Include member functions to calculate and set salary based on employee performance.*/

#include <iostream>
#include <string>
using namespace std;

class Employee{
private:
    string name;
    static int current_id;
    int id;
    double salary;
public:
    Employee(const string& n, double s) : name(n), salary(s) {
        id = current_id++;
    }
    void calcSalary(double performanceRating){
        if (performanceRating >= 0.0 && performanceRating <= 1.4){
            salary *= performanceRating;
            cout << "Salary Upgraded!" << endl;
        } 
        else {
            cout << "Invalid performanceRating salary remains the same" << endl;
        }
    }
    void setSalary(double newSalary){
        salary = newSalary;
    }
    double getSalary(){
        return salary;
    }
    string getName(){
        return name;
    }
    int getId(){
        return id;
    }

};

int Employee::current_id = 0;

int main() {
    Employee emp1("ricardo", 1500);
    Employee emp2("Alfredo", 2000);
    Employee emp3("Agnaldo", 8000);

    cout << "Salary of " << emp1.getName() << " (ID: " << emp1.getId() << "): " << emp1.getSalary() << endl;
    cout << "Calculating performanceRating..." << endl;
    emp1.calcSalary(1.1);
    cout << "Salary of " << emp1.getName() << " (ID: " << emp1.getId() << "): " << emp1.getSalary() << endl;

    cout << endl;

    cout << "Salary of " << emp2.getName() << " (ID: " << emp2.getId() << "): " << emp2.getSalary() << endl;
    cout << "Calculating performanceRating..." << endl;
    emp2.calcSalary(1.4);
    cout << "Salary of " << emp2.getName() << " (ID: " << emp2.getId() << "): " << emp2.getSalary() << endl;

    cout << endl;

    cout << "Salary of " << emp3.getName() << " (ID: " << emp3.getId() << "): " << emp3.getSalary() << endl;
    cout << "Calculating performanceRating..." << endl;
    emp3.calcSalary(-1);
    cout << "Salary of " << emp3.getName() << " (ID: " << emp3.getId() << "): " << emp3.getSalary() << endl;



    return 0;
}
