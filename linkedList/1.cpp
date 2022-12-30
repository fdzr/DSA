//
// Created by fzamora on 30-12-22.
//

#include "bits/stdc++.h"
#include "node/node.h"
#include "auxiliary_functions/aux_functions.h"

using namespace std;

bool hasCycle(ListNode *head) {
     ListNode *tmp = head;
    while(tmp != nullptr) {
        if(tmp->val == INT_MIN)
            return true;

        tmp->val = INT_MIN;
        tmp = tmp->next;
    }

    return false;
}

int main() {
    ListNode *head = nullptr;
    aux::insertAtEnd(&head, 1);
    aux::insertAtEnd(&head, 2);
    ListNode* tmp = head->next;


    aux::insertAtEnd(&head, 3);
    aux::insertAtEnd(&head, 4);
    aux::insertAtEnd(&head, 5);
    head->next->next->next = tmp;


    cout<<hasCycle(head);

    return 0;
}