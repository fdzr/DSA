#include "pila.h"

using namespace std;

template <typename T>
Pila<T>::Pila(int cap) {
    capacity = cap;
    arr = new T[capacity];
    top_ = -1;
}

template <typename T>
void Pila<T>::push(T elem) {
    if (!this->isFull()) {
        arr[++top_] = elem;
        return;
    }
    cout<<"Stack is full"<<endl;
}

template <typename T>
void Pila<T>::pop() {
    if(!this->isEmpty()) {
        --top_;
        return;
    }

    cout<<"Stack is empty"<<endl;
}

template <typename T>
T Pila<T>::top() {
    if (!this->isEmpty())
        return arr[top_];

    throw "Stack is empty...";
}

template <typename T>
bool Pila<T>::isFull() {
    return capacity == top_ + 1;
}

template <typename T>
bool Pila<T>::isEmpty() {
    return top_ == -1;
}

template<typename T>
void Pila<T>::print() {
    while(top_ > -1) {
        cout<<arr[top_--]<<" ";
    }
        
    cout<<endl;
}

template class Pila<int>;
