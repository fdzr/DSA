#include "queue.hpp"

int main()
{
    Queue q;
    q.print();

    try
    {
        q.dequeue();
    }
    catch (runtime_error e)
    {
        cout << e.what() << "\n";
        cout << "error ..." << "\n";
    }

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    cout << q.dequeue() << "\n";
    q.print();
    cout<<q.peek()<<"\n";
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    cout<<q.getSize()<<"\n";

    return 0;
}