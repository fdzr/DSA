#include "deque.hpp"

int main()
{
    CircularDeque cd(10);
    // cd.print();

    cd.insertRear(1);
    cd.insertRear(2);
    cd.insertRear(3);
    cd.insertRear(4);
    cd.print();

    cd.insertFront(5);
    cd.insertFront(6);
    cd.print();

    cout<<cd.front()<<"\n";
    cout<<cd.back()<<"\n";

    cd.removeBack();
    cd.print();

    cd.removeBack();
    cd.print();
    cd.removeBack();
    cd.print();

    cd.removeFront();
    cd.print();
    cd.removeFront();
    cd.print();
    cd.removeFront();
    cd.print();
    


    // cd.removeBack();
    // cd.removeBack();
    // cd.print();
    // cd.removeBack();
    // cd.print();

    // cd.removeBack();


    return 0;
}