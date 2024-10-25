#include <bits/stdc++.h>
#include "linkedList.hpp"

using namespace std;

int main() {
    LinkedList l;
    
    for(int i = 1; i <= 10; ++i)
        l.insertAtFront(i);

    l.print();

    l.reverse();
    
    l.print();
    l.insertAtEnd(11);
    l.print();
    l.insertAtFront(-1);
    l.print();
    l.reverse();
    l.print();

    
    

}