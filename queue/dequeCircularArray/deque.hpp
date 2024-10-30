#include <bits/stdc++.h>

using namespace std;

class CircularDeque
{
    int *arr;
    int head, rear;
    int size;

public:
    CircularDeque(int _capacity)
    {
        size = _capacity;
        head = -1;
        rear = 0;
        arr = new int[size];
    }

    void insertFront(int value)
    {
        if (isFull())
            throw runtime_error("Deque full...");

        if (isEmpty())
        {
            ++head;
            rear = 0;
            arr[head] = value;
            return;
        }
        if (head == 0)
        {
            head = size - 1;
        }
        else
        {
            --head;
        }

        arr[head] = value;
    }

    void insertRear(int value)
    {
        if (isFull())
            throw runtime_error("Deque is full...");

        if (isEmpty())
        {
            head = 0;
            rear = 0;
            arr[head] = value;
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = value;
    }

    int front()
    {
        if (head == -1)
            throw runtime_error("Deque is empty...");

        return arr[head];
    }

    int back()
    {
        if (head == -1)
            throw runtime_error("Deque is empty...");

        return arr[rear];
    }

    int removeBack()
    {
        if (isEmpty())
            throw runtime_error("Deque empty...");

        int value = arr[rear];

        rear = (rear == 0) ? size - 1 : rear - 1;

        if ((rear + 1) % size == head)
        {
            rear = 0;
            head = -1;
        }

        return value;
    }

    bool isFull()
    {
        return rear + 1 == head || (head == 0 && rear == size - 1);
    }

    bool isEmpty()
    {
        return head == -1 && rear == 0;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "\n";
            return;
        }

        int temp = head;

        while (true)
        {
            cout << arr[temp] << " ";

            if (temp == rear)
                break;

            temp = (temp + 1) % size;
        }

        cout << "\n";
    }
};