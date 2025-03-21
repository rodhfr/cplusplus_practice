#include <iostream>
#include <fstream>
#include <string>

using namespace std; 
  

int main (int argc, char *argv[]) {
  

  ofstream MyFile("filename.txt");

  MyFile << "Files can be tricky, but it is fun!" << endl;

  cout << endl;
  MyFile.close();

  string myText;

  ifstream MyReadFile("filename.txt");
  
  while (getline (MyReadFile, myText)) {
    cout << myText;
  }

  MyReadFile.close();


  return 0;
}
