#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
    string line;

    ifstream inputFile("textfile.txt");
    
    while (getline (inputFile, line)) {
        cout << line << endl;
    }
    
    inputFile.close();
    
}
