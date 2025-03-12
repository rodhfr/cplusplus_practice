// Write a C++ program to copy the contents of one text file to another.  

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main (int argc, char *argv[]) {
    string content, line;
    ifstream readFile("textfile.txt");

    while (getline (readFile, line)){
        content += line + " ";
    }

    ofstream writeFile("anothertxt.txt");
    writeFile << content << endl;

    cout << content << endl;
    
    
    return 0;
}
