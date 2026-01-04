#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode *head) {
    while(head) {
        cout<< head->val <<  " ";
        head = head->next;
    }
}

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    auto current = dummy;

    while (current->next) {
        auto firstNode = current->next;
        auto secondNode = current->next->next;

        if (!firstNode->next) break;

        firstNode->next = secondNode->next;
        secondNode->next = firstNode;

        current->next = secondNode;
        current = current->next, current = current->next;
    }

    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    printList(swapPairs(head));
    

    return 0;
}