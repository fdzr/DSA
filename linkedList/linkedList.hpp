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
        Node *temp = head, *aux, *auxHead = head, *prev = nullptr;

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

    void clear()
    {
        Node *temp = head, *aux = nullptr;
        while (temp != nullptr)
        {
            aux = temp->next;
            delete temp;
            temp = aux;
        }

        head = nullptr, tail = nullptr;
    }

    std::pair<bool, Node *> search(int key)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->value == key)
            {
                return std::make_pair(true, temp);
            }
            temp = temp->next;
        }

        return {false, nullptr};
    }

    bool removeKey(int key)
    {
        std::pair<bool, Node *> result = this->search(key);
        if (result.first == false)
            return false;

        Node *temp = head;

        if (temp == result.second)
        {
            head = head->next;
            delete temp;
            return true;
        }

        while (temp->next != result.second)
            temp = temp->next;

        Node *aux = temp->next;
        temp->next = result.second->next;
        delete aux;

        return true;
    }

    Node *findMiddleNode()
    {
        if (head == nullptr)
            return nullptr;

        Node *fast = head, *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node *getNthNode(int n)
    {
        if (n < 0 || this->size() <= n)
            return nullptr;

        Node *temp = head;
        while (n-- > 0)
            temp = temp->next;

        return temp;
    }

    Node *getNthNodeFromTheEnd(int n)
    {
        if (n < 0 || this->size() <= n)
            return nullptr;

        Node *temp = head;
        Node *aux = head;
        while (n-- > 0)
            temp = temp->next;

        while (temp != nullptr)
        {
            temp = temp->next;
            aux = aux->next;
        }

        return aux;
    }

    void print()
    {
        Node *tmp = head;

        while (tmp != nullptr)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }

        std::cout << "\n";
    }
};