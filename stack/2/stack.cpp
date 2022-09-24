#include "stack.h"

using namespace std;

Stack::Stack(): top_{nullptr} {}

void Stack::push(int elem) {
    Node * tmp = new Node();
    tmp->value = elem;
    
    if (!top_) {
        tmp->next = nullptr;
        top_ = tmp;
    }
    else {
        tmp->next = top_;
        top_ = tmp;
    }
    
}

int Stack::top() {
    if (!top_)
        throw "Stack empty";
    return top_->value;
}

void Stack::pop() {
    Node *tmp = top_;
    if (top_) {
        top_ = top_->next;
        delete tmp;
        tmp = top_;
    }
    
}

bool Stack::isEmpty() {
    return top_ == nullptr;
}

void Stack::print() {
    if (!this->isEmpty()) {
        Node* tmp = top_;
        while(tmp) {
            cout<<tmp->value<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
}

