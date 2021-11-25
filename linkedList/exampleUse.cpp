#include <iostream>
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

    while(tmp != nullptr){
        cout<<tmp->data<<endl;
        tmp = tmp->next;
    }



    return 0;
}