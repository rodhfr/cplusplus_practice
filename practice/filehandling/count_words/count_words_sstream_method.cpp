#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    ifstream inputFile("textfile.txt");

    if (inputFile.is_open()){
        string line;
        int wordCount = 0;

        while (getline (inputFile, line)){
            stringstream ss(line);
            string word;
            while (ss >> word){
                wordCount++;
            }
        }
        inputFile.close();
        cout << "Number of words in the said file: " << wordCount << endl;
    }
    else {
        cout << "Failed to open the file." << endl;
    }
    return 0;
}

