#include <bits/stdc++.h>
#include "../common/node.h"

class LinkedList
{
    Node *head, *tail;

public:
    LinkedList() : head{nullptr}, tail{nullptr} {}
    void insertAtFront(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void print()
    {
        Node *tmp = head;

        while (tmp != nullptr)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
    }
};