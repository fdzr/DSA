#include <iostream>
#include "queue.h"

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.print();

    return 0;
}