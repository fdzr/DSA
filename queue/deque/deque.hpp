#include <bits/stdc++.h>
#include "../../common/node.h"

using namespace std;

class Deque
{
    Node *head, *rear;

public:
    Deque() : head{nullptr}, rear{nullptr} {}

    void insertFront(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            rear = head;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            rear = head;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    int front()
    {
        if (isEmpty())
            throw runtime_error("Deque empty...");

        return head->value;
    }

    int back()
    {
        if (isEmpty())
            throw runtime_error("Deque empty...");

        return rear->value;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void print()
    {
        if (isEmpty())
            return;

        Node *temp = head;
        while (temp != rear)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << rear->value << "\n";
    }
};