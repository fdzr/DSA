#include <bits/stdc++.h>
#include "../common/node.h"

class LinkedList
{
    Node *head, *tail;

    int sizeAux(Node *temp)
    {
        if (temp == nullptr)
            return 0;

        return 1 + sizeAux(temp->next);
    }

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

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int size()
    {
        return sizeAux(head);
    }

    void reverse()
    {
        Node *temp = head, *aux, *auxHead=head, *prev = nullptr;

        while (temp != nullptr)
        {
            aux = temp->next;
            temp->next = prev;
            prev = temp;
            temp = aux;
        }

        head = tail;
        tail = auxHead;
    }

    void clear() {
        Node *temp = head, *aux = nullptr;
        while(temp != nullptr) {
            aux = temp->next;
            delete temp;
            temp = aux;
        }

        head = nullptr, tail = nullptr;
    }

    void print()
    {
        Node *tmp = head;

        while (tmp != nullptr)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }

        std::cout<<"\n";
    }
};