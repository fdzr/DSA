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

    void insertAfter(Node* prev, int data){
        if(!prev){
            cout<<"Node not founded";
            return;
        }
        
        Node* actual = new Node();
        actual->data = data;
        actual->next = prev->next;
        prev->next = actual;
    }

    void insertAtEnd(Node** ref, int data){
        Node* actual = new Node();
        actual->data = data;
        actual->next = nullptr;

        if (!*ref){
            *ref = actual;
            return;
        }

        Node* tmp = *ref;
        while(tmp->next)
            tmp = tmp->next;

        tmp->next = actual;
    }
}

#endif