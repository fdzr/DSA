//
// Created by fzamora on 30-12-22.
//
#include "bits/stdc++.h"
#include "auxiliary_functions/aux_functions.h"

using namespace std;

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = nullptr;
    while(head) {
        if(!slow && head->next == slow)
            return head;
        slow = head;
        head = head->next;
    }
    return nullptr;
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

    detectCycle(head);

    return 0;
}