#include <iostream>
#include "contaBancaria.h"

int main(void) {
    contaBancaria u1("Astolfo", 0);
    u1.depositar(500);
    u1.sacar(200);
    u1.sacar(2000);

    return 0;
}
