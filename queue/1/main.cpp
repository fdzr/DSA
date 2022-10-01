#include <iostream>
#include "queue.h"


int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    std::cout<<endl;
    q.dequeue();
    q.print();
    
    
    return 0;
}