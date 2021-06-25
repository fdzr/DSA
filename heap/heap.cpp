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


void MinHeap::decreaseKey(int i, int new_val){
    harr[i] = new_val;
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}


int MinHeap::extractMin(){
    if(heap_size <= 0)
        return INT_MAX;
    if(heap_size == 1){
        heap_size--;
        return harr[0];
    }
    
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}


void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}


void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}



