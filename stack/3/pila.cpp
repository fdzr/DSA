#include "pila.h"
using namespace std;

Pila::Pila() {}

void Pila::push(int elem) {
    principal.push(elem);

    if (aux.empty())
        aux.push(elem);

    else if(aux.top() >= elem){
        aux.push(elem);
    }
}

void Pila::pop() {
    if (principal.empty())
        throw "Stack empty";

    principal.pop();
    if(principal.top() == aux.top())
        aux.pop();
}

int Pila::getMinimumElement() {
    if (!aux.empty())
        return aux.top();
    throw "Stack empty";
}

void Pila::print(bool flag) {
    stack<int> st = (flag)? principal: aux;
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }

}