#ifndef NODE_H
#define NODE_H

class Node {
    public:
        int value;
        Node* next;
        Node(): next{nullptr}{}
        Node(int val): value{val}, next{nullptr} {}
};

#endif