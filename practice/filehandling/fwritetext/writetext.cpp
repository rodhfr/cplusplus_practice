#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ofstream MyFile("textfile.txt");
    
    MyFile << "some text into it";

   MyFile.close();
}