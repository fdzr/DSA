#include "deque.hpp"

int main()
{
    Deque d;
    d.print();

    d.insertFront(10);
    d.insertFront(10);
    d.insertFront(20);
    d.insertFront(40);
    d.print();

    return 0;
}