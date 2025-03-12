#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int countWords(const string& str) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; i < str.length(); i++){
        char ch = str[i];
        if (ch != ' ' && ch != '\t' && ch != '\n'){
            if (!inWord){
                count++;
                inWord = true;
            }
        }
        else {
            inWord = false;
        }
    }
    return count;
}
int main (int argc, char *argv[]) {
    ifstream readFile("textfile.txt");
    string content, line;

    while(getline(readFile, line)){
        content += line + " ";
    }
    cout << "this is the content: " << endl << content << endl;
    cout << "words number: " << endl << countWords(content) << endl;

    readFile.close();
    return 0;
}
