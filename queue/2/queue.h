#include <iostream>

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    int *arr;
    int capacity;
    int head;
    int tail;
    
    public:
        Queue(int cap);
        void enqueue(int elem);
        int dequeue();
        bool isFull();
        bool isEmpty();
        void print();
};

#endif