#include <iostream>
#include "../node/node.h"

using namespace std;

#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

namespace aux{
    void pushAtFront(Node** ref, int data){
        Node* new_node = new Node();
        new_node->data = data;   
        new_node->next = (*ref);
        (*ref) = new_node;
    }
}

#endif