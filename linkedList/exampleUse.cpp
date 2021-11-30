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

    aux::pushAtFront(&head, 0);
    aux::insertAfter(second, 5);
    aux::insertAtEnd(&head, 6);

    aux::print(&head);
    aux::deleteNode(&head, 0);
    aux::print(&head);

    aux::deleteNode(&head, 6);
    aux::print(&head);

    aux::deleteNode(&head, 5);
    aux::print(&head);
    
    aux::deleteNode(&head, 10);
    aux::print(&head);

    aux::deleteNodeAtGivenPosition(&head, 0);
    aux::print(&head);

    aux::print(&head);
    aux::deleteNodeAtGivenPosition(&head, 2);
    aux::print(&head);

    aux::print(&head);
    aux::deleteNodeAtGivenPosition(&head, 1);
    aux::print(&head);


    return 0;
}