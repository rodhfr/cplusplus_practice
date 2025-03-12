/*8. Write a C++ program to implement a class called Date that has private member variables for day, month, and year. Include member functions to set and get these variables, as well as to validate if the date is valid.*/


#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    void setDay(int d){
        if (d > 0 && d < 30){
            day = d;
        }
    }
    void setMonth(int m){
        month = m;
    }
    void setYear(int y){
        year = y;
    }
    int getDay(){
        return day;
    } int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
protected:
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
