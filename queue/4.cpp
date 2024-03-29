#include <bits/stdc++.h>

using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(d.size() < capacity) {
            d.push_front(value);
            return true;
        }

        return false;
    }
    
    bool insertLast(int value) {
        if(d.size() < capacity) {
            d.push_back(value);
            
            return true;
        }

        return false;
    }
    
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        d.pop_front();
        
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }
        d.pop_back();
        
        return true;
    }
    
    int getFront() {
        return isEmpty()? -1 : d.front();
    }
    
    int getRear() {
        return isEmpty()? -1 : d.back();
    }
    
    bool isEmpty() {
        return d.empty() == true;
    }
    
    bool isFull() {
        return d.size() == capacity;
    }

private:
    deque<int> d;
    int capacity;
};

int main() {


    return 0;
}