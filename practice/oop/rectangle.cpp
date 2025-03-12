//Write a C++ program to create a class called Rectangle that has private member variables for length and width. Implement member functions to calculate the rectangle's area and perimeter


#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
public:
    Rectangle(double comprimento, double largura) : length(comprimento), width(largura) {}
    double getArea(){
        return length * width;
    }
    double getPerimeter(){
        return 2 * (length + width);
    }
};

int main() {
    Rectangle ret1(20, 10);

    /*cout << "Hello, World!" << endl;*/
    cout << "Area: " << ret1.getArea() << endl;
    cout << "Perimeter: " << ret1.getPerimeter() << endl;
    return 0;
}
