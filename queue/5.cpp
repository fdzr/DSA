#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        capacity = k;
        front = 0;
        tail = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        arr[(tail + 1) % capacity] = value;
        tail = (tail + 1) % capacity;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;

        if(front == tail) {
            tail = -1;
            front = 0;
        } else {
            front = (front + 1) % capacity;
        }

        return true;
    }
    
    int Front() {
        return isEmpty()? -1 : arr[front];
    }
    
    int Rear() {
        return isEmpty()? -1: arr[tail];
    }
    
    bool isEmpty() {
        return tail == -1;
    }
    
    bool isFull() {
        if(tail == -1)
            return false;
        return (tail + 1) % capacity == front;
    }

private:
    int *arr;
    int capacity;
    int front;
    int tail;
};

int main() {
    MyCircularQueue m(3);
    cout<<m.enQueue(1)<<endl;
    cout<<m.enQueue(2)<<endl;
    cout<<m.enQueue(3)<<endl;
    cout<<m.enQueue(4)<<endl;
    cout<<m.deQueue()<<endl;
    cout<<m.deQueue()<<endl;
    cout<<m.deQueue()<<endl;
    cout<<m.isEmpty()<<endl;
    cout<<m.enQueue(1)<<endl;
    cout<<m.enQueue(2)<<endl;
    cout<<m.enQueue(3)<<endl;
    cout<<m.Rear()<<endl;
    cout<<m.Front()<<endl;
    cout<<m.deQueue()<<endl;
    cout<<m.Front()<<endl;

    return 0;
}