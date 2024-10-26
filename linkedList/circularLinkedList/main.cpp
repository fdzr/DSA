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

    return 0;
}