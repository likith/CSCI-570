#ifndef HEAP_H
#define HEAP_H

class Heap
{
    int mSize;
    int mCurrentSize;
    int* mHeap;
    int mMinIndex;

public:
    Heap(int size);
    ~Heap();

    int insert(int value);
    void heapifyUp(int index);
    void heapifyDown(int index);
    int deleteItem(int index);
    int findMin();
    int extractMin();
    void print();

};

#endif //HEAP_H