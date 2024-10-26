#include <bits/stdc++.h>
#include "../../common/node.h"

class CircularLinkedlist
{
    Node *tail;

public:
    CircularLinkedlist() : tail{nullptr} {}

    bool insertAtFront(int value)
    {
        Node *newNode = new Node(value);
        if (this->isEmpty())
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            Node *aux = tail->next;
            newNode->next = aux;
            tail->next = newNode;
        }

        return true;
    }

    bool isEmpty()
    {
        return tail == nullptr;
    }

    void print()
    {
        Node *head = tail->next;
        while (head)
        {
            std::cout << head->value << " ";
            if (head == tail)
                break;

            head = head->next;
        }

        std::cout << "\n";
    }
};