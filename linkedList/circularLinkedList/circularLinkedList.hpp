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

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (this->isEmpty())
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool insertAtSpecificPosition(int pos, int value)
    {
        int len = this->size();
        if (pos < 1 || pos > len)
            return false;

        Node *prev = nullptr;
        Node *temp = tail;
        Node *newNode = new Node(value);

        while (pos-- > 0)
        {
            prev = temp;
            temp = temp->next;
        }

        newNode->next = temp;
        prev->next = newNode;
        if(len == pos)
            tail = newNode;

        return true;
    }

    bool isEmpty()
    {
        return tail == nullptr;
    }

    int size()
    {
        if (tail == nullptr)
            return 0;

        Node *temp = tail->next;
        int cont = 1;

        while (temp != tail)
        {
            cont++;
            temp = temp->next;
        }

        return cont;
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