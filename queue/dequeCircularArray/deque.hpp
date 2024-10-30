#include <bits/stdc++.h>

using namespace std;

class CircularDeque
{
    int *arr;
    int front, rear;
    int size;

public:
    CircularDeque(int _capacity)
    {
        size = _capacity;
        front = -1;
        rear = 0;
        arr = new int[size];
    }

    void insertFront(int value)
    {
        if (isFull())
            throw runtime_error("Deque full...");

        if (isEmpty())
        {
            ++front;
            rear = 0;
            arr[front] = value;
            return;
        }
        if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            --front;
        }

        arr[front] = value;
    }

    void insertRear(int value)
    {
        if (isFull())
            throw runtime_error("Deque is full...");

        if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[front] = value;
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = value;
    }

    bool isFull()
    {
        return rear + 1 == front || (front == 0 && rear == size - 1);
    }

    bool isEmpty()
    {
        return front == -1 && rear == 0;
    }

    void print()
    {
        if (isEmpty())
            return;

        int temp = front;

        while (true)
        {
            cout << arr[temp] << " ";

            if (temp == rear)
                break;

            temp = (temp + 1) % size;
        }

        cout<<"\n";
    }
};