#include <iostream>
#include "queue.h"

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    cout<<q.isFull()<<endl;
    cout<<q.dequeue()<<endl;
    q.print();
    cout<<q.dequeue()<<endl;
    q.print();
    q.enqueue(1);
    q.print();
    cout<<q.dequeue()<<endl;
    q.print();
    q.enqueue(2);
    q.print();
    q.enqueue(3);
    q.print();
    try {
        q.enqueue(6);
    } catch(const char* msg) {
        cout<<msg;
    }
    

    return 0;
}