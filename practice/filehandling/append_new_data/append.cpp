// 7 Write a C++ program to append new data to an existing text file.  
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    
    ifstream readFile("textfile.txt");
    
    if (readFile.is_open()){
        string line, content, append_string;
        while (getline (readFile, line)){
            content += line + " ";
        }

        append_string = " This is the appendend content \n" ;
        content += append_string;

        ofstream writeFile("textfile.txt");
        writeFile << content;

        readFile.close();
        writeFile.close();
    }
    else {
        cout << "Failed to open the file." << endl;
    }
    return 0;

}
