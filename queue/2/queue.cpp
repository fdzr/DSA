#include "queue.h"

Queue::Queue(int cap): arr{new int[cap]}, capacity{cap} {
    tail = head = -1;
}

void Queue::enqueue(int elem) {
    if (isFull())
        throw "Queue is full";
    if(isEmpty()) {
        arr[++head] = elem;
        ++tail;
        return;
    }

    tail = (tail + 1) % capacity;
    arr[tail] = elem;
}

int Queue::dequeue() {
    if(isEmpty())
        throw "Queue empty";

    int return_head = arr[head];
    head = (head + 1) % capacity;
    return return_head;
}

bool Queue::isFull() {
    return (tail+1) % capacity == head;
}

bool Queue::isEmpty() {
    return tail == -1;
}

void Queue::print() {
    if(isEmpty())
        cout<<"Queue empty"<<endl;

    if(head == tail){
        cout<<arr[head]<<endl;
        return;
    }

    int tmp_head = head, tmp_tail = tail;
    while(1) {
        cout<<arr[tmp_head]<<" ";
        tmp_head = (tmp_head + 1) % capacity;
        if(tmp_head == tmp_tail) {
            cout<<arr[tmp_head]<<" ";
            break;
        }
    }

    cout<<endl;

}