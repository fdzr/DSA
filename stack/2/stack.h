#include <iostream>
#include "../../common/node.h"

#ifndef STACK_H
#define STACK_H

class Stack {
    Node* top_;

    public:
        Stack();
        void push(int value);
        void pop();
        int top();
        bool isEmpty();
        void print();
};

#endif