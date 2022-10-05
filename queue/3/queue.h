#include <iostream>
#include <stack>

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    stack<int> s1, s2;
    void fillStack(stack<int> &pila_1, stack<int> &pila_2) {
        while(!pila_1.empty()) {
            pila_2.push(pila_1.top());
            pila_1.pop();
        }
    }
 
    public:
        Queue() = default;
        bool isEmpty() { return s1.empty();}
        void enqueue(int elem) {
            if (s1.empty() && s2.empty()){ 
                s2.push(elem);
                return;
            }
            
            fillStack(s2, s1);
            s1.push(elem);
            fillStack(s1, s2);
            
        }
        int dequeue() {
            if (s2.empty())
                throw "Queue empty";

            int return_value = s2.top();
            s2.pop();
            return return_value;
        }
        void print() {
            decltype(s2) tmp = s2;
            while(!tmp.empty()) {
                cout<<tmp.top()<<" ";
                tmp.pop();
            }
            cout<<endl;
        }
};

#endif