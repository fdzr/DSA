#include "heap.h"

MinHeap::MinHeap(int c): heap_size{0}, capacity{c}, harr{new int[c]} {}

void MinHeap::insertKey(int k){
    if(heap_size == capacity){
        cout<<"Overflow...";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}



