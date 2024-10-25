#include <bits/stdc++.h>
#include "linkedList.hpp"

using namespace std;

int main() {
    LinkedList l;
    
    for(int i = 0; i < 10; ++i)
        l.insertAtFront(i);

    l.print();

}