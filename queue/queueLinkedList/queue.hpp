#include <bits/stdc++.h>

using namespace std;

class Queue
{
    list<int> *q;

public:
    Queue() : q{new list<int>()} {}
    
    ~Queue()
    {
        cout<<"destroying..."<<"\n";
        delete q;
    }

    void enqueue(int value)
    {
        q->push_back(value);
    }

    int dequeue()
    {
        int val = q->front();
        q->pop_front();
        return val;
    }

    void print()
    {
        for (const int &elem : *q)
            cout << elem << " ";
        cout<<"\n";
    }
};