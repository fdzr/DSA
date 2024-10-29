#include <bits/stdc++.h>
#include "queue.hpp"

using namespace std;

int main()
{
    CircularQueue q(2);
    q.insert(1);
    q.insert(2);
    q.print();
    q.insert(3);
    q.print();
    cout<<q.get()<<"\n";
    q.print();

    return 0;
}