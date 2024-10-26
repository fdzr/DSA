#include <bits/stdc++.h>
#include "circularLinkedList.hpp"

using namespace std;

int main() {
    CircularLinkedlist *c = new CircularLinkedlist;
    c->insertAtFront(10);
    c->insertAtFront(9);
    c->print();

    c->insertAtEnd(11);
    c->insertAtEnd(12);
    c->insertAtFront(8);
    c->print();

    c->insertAtSpecificPosition(3, 21);
    c->print();

    c->insertAtSpecificPosition(5, 31);
    c->print();

    c->insertAtSpecificPosition(1, 51);
    c->print();

    cout<<c->size()<<"\n";

    bool inserted = c->insertAtSpecificPosition(-1, 69);
    cout<<boolalpha<<inserted<<"\n";

    c->insertAtSpecificPosition(8, 89);
    cout<<c->size()<<"\n";
    c->print();

    c->deleteFirstNode();
    c->print();
    cout<<c->size()<<"\n";

    c->deleteFirstNode();
    c->print();
    cout<<c->size()<<"\n";

    c->deleteNode(11);
    c->print();
    cout<<c->size();

    return 0;
}