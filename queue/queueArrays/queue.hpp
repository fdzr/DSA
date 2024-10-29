#include <bits/stdc++.h>

class CircularQueue
{
    int *arr;
    int size;
    int front;
    int tail;
    int capacity;

public:
    CircularQueue(int _capacity) : capacity{_capacity}, size{0}, front{0}, tail{-1}
    {
        arr = new int[capacity];
    }

    void insert(int elem)
    {
        if (size == capacity)
            this->resize();

        arr[(tail + 1) % capacity] = elem;
        tail = (tail + 1) % capacity;
        ++size;
    }

    int get()
    {
        if (size == 0)
            throw std::runtime_error("Queue is empty");

        int value = arr[front];
        front = (front + 1) % capacity;
        --size;
        return value;
    }

    void resize()
    {
        int *temp = new int[capacity * 2];
        for (int i = 0; i < size; ++i)
            temp[i] = arr[(front + i) % capacity];

        delete[] arr;
        arr = temp;
        front = 0;
        tail = size - 1;

        capacity *= 2;
    }

    void print()
    {
        int temp = front;
        while(temp != tail)
        {
            std::cout << arr[temp] << " ";
            temp  = (temp + 1) % capacity;

        }
        std::cout << arr[tail] << " ";
        std::cout << "\n";
    }
};