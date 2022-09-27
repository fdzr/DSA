#include <iostream>
#include "pila.h"

using namespace std;

int main() {
    Pila p;  
    p.push(7);
    cout<<p.getMinimumElement()<<endl;
    p.push(10);
    cout<<p.getMinimumElement()<<endl;
    p.push(6);
    cout<<p.getMinimumElement()<<endl;
    p.push(5);
    cout<<p.getMinimumElement()<<endl;
    p.push(4);
    cout<<p.getMinimumElement()<<endl;
    p.push(8);
    cout<<p.getMinimumElement()<<endl;

    return 0;
}