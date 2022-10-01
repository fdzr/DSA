#include "../../common/node.h"
#include <iostream>

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    Node *front, *tail;

    public:
        Queue();
        void enqueue(int n);
        int dequeue();
        void print();
};

#endif