#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class pessoa {
public:
    int id;
    string nome;
};

int main(void) {

    pessoa p1;
    pessoa* pp1 = &p1;

    p1.id = 10;
    pp1->id = 11;

    cout << "Pessoa p1.id = " << p1.id << endl;

    pessoa* pp2 = new pessoa;

    pp2->id = 20;

    cout << "Pessoa* pp2->id = " << pp2->id << endl;

    delete pp2;

    int tamanho = 5;

    pessoa arp1[5];
    
    for (int i = 0; i < 5; i++){
        arp1[i].id = i * 10;
    }

    for (int i = 0; i < 5; i++){
        cout << "Pessoa arp1[" << i << "].id = " << arp1[i].id << endl;
    }


    pessoa* arp2 = new pessoa[tamanho];
        
    for (int i = 0; i < 5; i++){
        arp2[i].id = i * 100;
    }

    for (int i = 0; i < 5; i++){
        cout << "Pessoa arp2[" << i << "].id = " << arp2[i].id << endl;
    }

    delete[] arp2;



    return 0;


}
