#include <bits/stdc++.h>
#include "../../common/node.h"

using namespace std;

class Deque
{
    Node *head, *rear;

    Node *getBeforeLastNode()
    {
        if (isEmpty() || head == rear)
            return nullptr;

        Node *temp = head;
        while (temp->next != rear)
            temp = temp->next;

        return temp;
    }

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

    int removeFront()
    {
        if (isEmpty())
            throw runtime_error("Deque empty...");

        int val = head->value;
        Node *aux = head;
        head = head->next;
        delete aux;

        return val;
    }

    int removeBack()
    {
        if (isEmpty())
            throw runtime_error("Deque empty...");

        int val = rear->value;
        Node *aux = rear;
        Node *newLastNode = getBeforeLastNode();
        if (newLastNode == nullptr)
        {
            delete head;
            delete rear;
            head = nullptr;
            rear = nullptr;
            return val;
        }

        rear = newLastNode;

        return val;
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