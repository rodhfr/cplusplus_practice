// Write a C++ program to implement a class called Circle that has private member variables for radius. Include member functions to calculate the circle's area and circumference. 

#include <iostream>
using namespace std;

class Circle {
private:
    float radius;
    float area;
public:
    Circle(int r) : radius(r), area(3.14 * r * r) {}

    double getArea() const {
        return area;
    }
    double getCircumference() {
        return (2 * 3.14 * radius);
    }
};

int main() {
    Circle myCircle(5.0);

    cout << "area: " << myCircle.getArea() << endl;
    cout << "circumference : " << myCircle.getCircumference() << endl;
    
    return 0;
}
