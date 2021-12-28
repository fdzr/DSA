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
    aux::insertAtEnd(&head, 6);
    aux::insertAtEnd(&head, 6);

    aux::print(&head);
    // aux::deleteNode(&head, 0);
    // aux::print(&head);

    // aux::deleteNode(&head, 6);
    // aux::print(&head);

    // aux::deleteNode(&head, 5);
    // aux::print(&head);
    
    // aux::deleteNode(&head, 10);
    // aux::print(&head);

    // aux::deleteNodeAtGivenPosition(&head, 0);
    // aux::print(&head);

    // aux::print(&head);
    // aux::deleteNodeAtGivenPosition(&head, 2);
    // aux::print(&head);

    // aux::print(&head);
    // aux::deleteNodeAtGivenPosition(&head, 1);
    // aux::print(&head);

    // aux::deleteList(&head);
    // aux::print(&head);

    // cout<<aux::lengthListRecursive(&head)<<endl;
    // cout<<aux::lengthListRecursive(&head);

    // cout<<aux::findValueRecursive(&head, 15)<<endl;
    // cout<<aux::findValueIterative(&head, 5)<<endl;
    
    // auto temp = aux::findNthNode(head, 3, 0);

    // if (temp)
    //     cout<<"Node found, value "<<temp->data<<endl;
    // else
    //     cout<<"Not found"<<endl;

    // cout<<"Element at index 3 is: "<<aux::findNthNode(head, 3)<<endl;

    // aux::printNthNodeBackward(head, 3);
    // aux::printNthNodeBackwardRecursively(head, 4);    
    // aux::getMiddleNode(head);
    // cout<<aux::countGivenNode(head, 6)<<endl;
    // cout<<aux::countGivenNodeRecursively(head, 6)<<endl;
    // cout<<aux::countGivenNodeRecursively2Version(head, 6)<<endl;
    // cout<<aux::countGivenNodeRecursively3Version(head, 6)<<endl;
    cout<<aux::detectLoopInLinkedList(head);

    return 0;
}