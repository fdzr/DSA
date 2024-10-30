#include "deque.hpp"

int main()
{
    Deque d;
    d.print();
    try
    {
        d.front();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    d.insertFront(10);
    d.insertFront(10);
    d.insertFront(20);
    d.insertFront(40);
    d.print();

    d.insertEnd(-10);
    d.insertEnd(-20);
    d.print();

    cout << d.front() << "\n";
    cout << d.back() << "\n";

    d.removeFront();
    d.print();

    d.removeBack();
    d.print();
    d.removeBack();
    d.print();


    return 0;
}