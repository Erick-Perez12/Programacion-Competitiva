#include "heap.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

void MaxHeap::heapifyUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void MaxHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(static_cast<int>(heap.size()) - 1);
}

void MaxHeap::heapifyDown(int index) {
    int size = static_cast<int>(heap.size());
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::extractMax() {
    if (heap.empty()) {
        return;
    }
    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty()) {
        heapifyDown(0);
    }
}

int MaxHeap::getMax() const {
    if (heap.empty()) {
        throw std::out_of_range("El heap esta vacio");
    }
    return heap[0];
}

bool MaxHeap::empty() const {
    return heap.empty();
}

void MaxHeap::print() const {
    for (int value : heap) {
        std::cout << value << " ";
    }

    std::cout << std::endl;
}
