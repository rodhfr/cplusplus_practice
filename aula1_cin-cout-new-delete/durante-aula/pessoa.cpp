#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class pessoa {
private:
    int id;
    string nome;
public:
    int get_id() { return id; }
    void set_id(int i) { id = i; }
};

int main(void) {
    pessoa p1;

    p1.set_id(344);

    cout <<p1.get_id();
}
