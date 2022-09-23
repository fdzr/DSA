#include <iostream>

using namespace std;

#ifndef PILA_H
#define PILA_H

template <typename T>
class Pila{
    private:
        T *arr;
        int capacity;
        int top_;

    public:
        Pila(int cap);
        void push(T value);
        void pop();
        T top();
        bool isEmpty();
        bool isFull();
        void print();
};

#endif