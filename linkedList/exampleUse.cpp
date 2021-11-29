#include <iostream>
#include "auxiliary_functions/aux_functions.h"
#include "node/node.h"

using namespace std;

int main(){
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; 
    head->next = second;
 
    second->data = 2;
    second->next = third;
 
    third->data = 3;
    third->next = nullptr;

    auto tmp = head;

    aux::pushAtFront(&head, 0);

    while(head != nullptr){
        cout<<head->data<<endl;
        head = head->next;
    }



    return 0;
}