#include <iostream>
#include "pila.h"


int main() {
    Pila<int> pl(3);
    pl.push(1);
    pl.push(2);
    pl.push(3);
    pl.print();

    return 0;
}