#include <iostream>
#include <climits>

using namespace std;

#ifndef heap_H
#define heap_H


class MinHeap{
    int *harr;
    int capacity;
    int heap_size;
    
    public:
        MinHeap(int c);
        void MinHeapify(int);
        int extractMin();
        void decreaseKey(int i, int new_val);
        void deleteKey(int i);
        void insertKey(int k);

        int parent(int i) const {return (i-1)/2;}
        int left(int i) const {return 2*i + 1;}
        int right(int i) const {return 2*i + 2;}
        int getMin() {return harr[0];}
};


#endif
