/*6. Write a C++ program to create a class called Triangle that has private member variables for the lengths of its three sides. Implement member functions to determine if the triangle is equilateral, isosceles, or scalene. */

#include <iostream>
using namespace std;

class Triangle {
private:
    double side_a, side_b, side_c;
public:
    Triangle(double a, double b, double c) : side_a(a), side_b(b), side_c(c){}

    void print_type(){
        if (side_a == side_b == side_c){
            cout << "equilateral" << endl;
        }
        else if (side_a != side_b != side_c){
            cout << "scalene" << endl;
        }
        else {
            cout << "isosceles" << endl;
        }
    }
};

int main() {
    Triangle t1(20, 30, 40);

    cout << "Triangle type: ";
    t1.print_type();
    return 0;
}
