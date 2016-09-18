#include <iostream>
#include <vector>
#include "heap.h"

Heap::Heap(int size){
    mSize = size;
    mCurrentSize = 0;
    mMinIndex = 1;
    mHeap = new int[size+1];
}

Heap::~Heap(){
    mSize = 0;
    mCurrentSize = 0;
    delete[] mHeap;
}

int Heap::insert(int value){
    if(mCurrentSize >= mSize){
        std::cout << "\nHeap is Full.\n";
        return -1;
    }

    mCurrentSize++;
    mHeap[mCurrentSize] = value;
    heapifyUp(mCurrentSize);


    return 0;
}

void Heap::heapifyUp(int index){

    for(int i = index; i > 1; i = i/2){
        int parent = i/2;
        if(mHeap[parent] > mHeap[i]){
            int temp = mHeap[parent];
            mHeap[parent] = mHeap[i];
            mHeap[i] = temp;
        }
        else{
            break;
        }
    }
}

void Heap::heapifyDown(int index){

    for(int i = index; 2*i <= mCurrentSize; ){
        int c_index = 2*i;

        if((c_index + 1) <= mCurrentSize && mHeap[c_index+1] < mHeap[c_index]){
            //c_index = 2*i+1;
            c_index++;
        }

        if(mHeap[c_index] < mHeap[i]){
            int temp = mHeap[c_index];
            mHeap[c_index] = mHeap[i];
            mHeap[i] = temp;
        }
        else{
            break;
        }
        i = c_index;
    }
}

int Heap::deleteItem(int index){

    if(index > mCurrentSize){
        std::cout << "\nInvalid Index\n";
        return -1;
    }

    int del_item = mHeap[index];
    mHeap[index] = mHeap[mCurrentSize];
    mCurrentSize--;

    heapifyUp(index);
    heapifyDown(index);

    return 0;
}

int Heap::findMin(){

    if(mCurrentSize <= 0){
        std::cout << "\nNo Element in Heap\n";
        return -1;
    }

    return mHeap[mMinIndex];
}

int Heap::extractMin(){

    if(mCurrentSize <= 0){
        std::cout << "\nNo Element in Heap\n";
        return -1;
    }

    mHeap[mMinIndex] = mHeap[mCurrentSize];
    mCurrentSize--;
    std::cout << "\n Extract Min mCurrentSize " << mCurrentSize << "\n";
    heapifyDown(mMinIndex);

    return 0;
}

void Heap::buildHeap(std::vector<int>& heap_in){

    for(int i = 0; i < mSize; i++){
        mHeap[i+1] = heap_in[i];
    }
    mCurrentSize = mSize;

    for(int i = mSize/2; i > 0; i--){
        heapifyDown(i);
    }
}

void Heap::print(){

    std::cout << "\n Heap Items\n";
    for(int i=1; i <= mCurrentSize; i++){
        std::cout << mHeap[i] << "\n";
    }
}

int main()
{
    int size;

    std::cout << "\nEnter the size of the heap\n";
    std::cin >> size;

    Heap* h = new Heap(size);
    bool loop = true;

    while(loop){
        std::cout << "\n1. Insert 2. Find Min 3. Delete 4. Extract Min 5. Print 6. Build Heap 7. Exit\n";
        int choice;
        std::cin >> choice;
        switch(choice){
            case 1: std::cout << "\nEnter item to insert\n";
                int item;
                std::cin >> item;
                h->insert(item);
                break;

            case 2: std::cout << "\n Min is " << h->findMin() << "\n";
                break;

            case 3: std::cout << "\n Enter index to delete \n";
                int index;
                std::cin >> index;
                h->deleteItem(index);
                break;

            case 4: std::cout << "\n Extracting Min \n";
                h->extractMin();
                break;

            case 5: h->print();
                break;

            case 6: std::cout << "\n Enter " << size << " elements to the heap \n";
                {
                    std::vector<int> heap_in(size);
                    for(int i = 0; i < size; i++){
                        std::cin >> heap_in[i];
                    }
                    h->buildHeap(heap_in);
                }
                break;

            case 7: delete h;
                loop = false;
                break;

            default: std::cout << "\n Invalid choice. Enter the correct choice.\n";
        }
    }

    return 0;
}