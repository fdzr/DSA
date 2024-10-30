#include <bits/stdc++.h>
#include "../../common/node.h"

using namespace std;

class Queue
{
    Node *head, *tail;
    int size;

public:
    Queue() : head{nullptr}, tail{nullptr}, size{0} {}

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            ++size;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        ++size;
    }

    void print()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        while (temp != tail)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << tail->value << "\n";
    }
};