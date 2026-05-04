#ifndef HEAP_H
#define HEAP_H

#include <vector>

class MaxHeap {
public:
    void insert(int value);
    void extractMax();
    int getMax() const;
    bool empty() const;
    void print() const;

private:
    std::vector<int> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif
