#include "queue.h"

Queue::Queue(): front{nullptr}, tail{nullptr} {}

void Queue::enqueue(int elem) {
    Node *tmp = new Node();
    tmp->value = elem;
    tmp->next = nullptr;

    if(!front) {
        front = tmp;
        tail = front;
    } else {
        tail->next = tmp;
        tail = tail->next;
    }
}

int Queue::dequeue() {
    if(!front)
        throw "Queue empty";

    Node *tmp = front;
    int res = tmp->value;
    front = front->next;
    delete tmp;
    return res;
}

void Queue::print() {
    for(auto ptr = front; ptr!=nullptr; ptr=ptr->next)
        std::cout<<ptr->value<<" ";
}
