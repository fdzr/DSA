#include <bits/stdc++.h>
#include "../../common/node.h"

using namespace std;

class Deque
{
    Node *front, *rear;

public:
    Deque() : front{nullptr}, rear{nullptr} {}

    void insertFront(int value)
    {
        Node *newNode = new Node(value);

        if (front == nullptr)
        {
            front = newNode;
            rear = front;
            return;
        }

        newNode->next = front;
        front = newNode;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void print()
    {
        if (isEmpty())
            return;

        Node *temp = front;
        while (temp != rear)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << rear->value << "\n";
    }
};