#include <iostream>
#include <stack>
#include <list>

using namespace std;

#ifndef PILA_H
#define PILA_H

class Pila {
    stack<int> principal, aux;
    public:
        Pila();
        void push(int elem);
        void pop();
        int top();
        int getMinimumElement();
        void print(bool type);
};

#endif