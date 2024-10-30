// #include <bits/stdc++.h>
#include "queue.hpp"

// using namespace std;

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.print();
    q.dequeue();
    q.print();

    cout<<"\n";

    return 0;
}