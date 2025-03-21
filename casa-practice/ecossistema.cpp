#include <iostream>
using namespace std;

class OrganismoBase {
public:
    virtual void realizar_acao() = 0;
}

class Leao : public organismo_base {
private:
public:
    void realizar_acao() override {
        cout << "Leao Ruge [OrganismoBase::Leao realizar_acao()]"
    }

}

class Leopardo : public organismo_base {
private:
public:
    void realizar_acao() override {
        cout << "Leopardo Ruge [OrganismoBase::Leopardo realizar_acao()]"
    }

}

class Tartaruga : public organismo_base {
private:
public:
    void realizar_acao() override {
        cout << "Tartaruga Ruge [OrganismoBase::Tartaruga realizar_acao()]"
    }

}

class Vaca : public organismo_base {
private:
public:
    void realizar_acao() override {
        cout << "Vaca Ruge [OrganismoBase::Vaca realizar_acao()]"
    }

}

int main() {
    return 0;
}
