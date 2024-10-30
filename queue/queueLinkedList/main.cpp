#include "queue.hpp"

int main()
{
    Queue q;
    q.print();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();

    return 0;
}