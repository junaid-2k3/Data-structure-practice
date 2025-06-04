#include <iostream>
using namespace std;

// Implementing a Max Heap
class Heap {
private:
    int* heap;
    int capacity;
    int size;

    // Private helper methods
    int get_parent(int i) {
        return (i - 1) / 2;
    }

    int get_leftchild(int i) {
        return 2 * i + 1;
    }

    int get_rightchild(int i) {
        return 2 * i + 2;
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify_up(int nodeindex) {
        int parentIndex = get_parent(nodeindex);
        if (nodeindex > 0 && heap[parentIndex] < heap[nodeindex]) {
            swap(heap[parentIndex], heap[nodeindex]);
            heapify_up(parentIndex);
        }
    }

    void heapify_down(int nodeindex) {
        int largest = nodeindex;
        int leftchild = get_leftchild(nodeindex);
        int rightchild = get_rightchild(nodeindex);

        if (leftchild < size && heap[leftchild] > heap[largest]) {
            largest = leftchild;
        }
        if (rightchild < size && heap[rightchild] > heap[largest]) {
            largest = rightchild;
        }

        if (largest != nodeindex) {
            swap(heap[nodeindex], heap[largest]);
            heapify_down(largest);
        }
    }

    bool heapIsFull() {
        if (size == capacity) cout << "\n\tHeap Overflow ";
        return (size == capacity);
    }

    bool heapIsEmpty() {
        if (size == 0) cout << "\n\tHeap Underflow ";
        return (size == 0);
    }

public:
    Heap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[cap];
    }

    void insert(int value) {
        if (heapIsFull()) {
            cout << "Heap is full\n";
            return;
        }
        heap[size] = value;
        heapify_up(size);
        size++;
    }

    void deleteValue(int index) {
        if (index >= 0 && index < size) {
            heap[index] = heap[size - 1];
            size--;
            heapify_down(index);
        }
    }

    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify_down(i);
        }
    }

    void heapSort() {
        buildHeap(); // Ensure heap is built
        int originalSize = size;
        for (int i = size - 1; i >= 1; i--) {
            swap(heap[0], heap[i]);
            size--;
            heapify_down(0);
        }
        size = originalSize; // Restore original size
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    ~Heap() {
        delete[] heap;
    }
};

// Sample main() for testing
int main() {
    Heap h(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);
    h.insert(10);

    cout << "Heap before sorting:\n";
    h.printHeap();

    h.heapSort();

    cout << "Heap after Heap Sort:\n";
    h.printHeap();

    return 0;
}
