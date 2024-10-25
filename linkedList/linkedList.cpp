#include <bits/stdc++.h>
#include "linkedList.hpp"

using namespace std;

int main() {
    LinkedList l;
    
    for(int i = 1; i <= 10; ++i)
        l.insertAtFront(i);

    Node* result = l.findMiddleNode();
    cout<<result->value<<"\n";

    l.print();

    l.reverse();
    
    l.print();
    l.insertAtEnd(11);
    l.print();
    l.insertAtFront(-1);
    l.print();
    l.reverse();
    l.print();

 

    auto const&[found, node] = l.search(14);
    cout<<boolalpha<<found<<"\n";

    auto p = l.search(10);
    cout<<p.second->value<<"\n";

    bool removed = l.removeKey(10);
    cout<<boolalpha<<removed<<"\n";
    l.print();

    l.removeKey(-1);
    l.print();
    l.removeKey(11);
    l.print();
    l.removeKey(15);
    l.print();

    auto temp = l.getNthNode(3);
    cout<<temp->value<<"\n";

    l.clear();
    l.print();

    return 0;
    
}