#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i)  { return (i - 1) / 2; }
    int left(int i)    { return 2 * i + 1; }
    int right(int i)   { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] > heap[largest]) largest = l;
        if (r < heap.size() && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void removeMax() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }
        cout << "Removing max: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
     void buildHeap(const vector<int>& arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
            heapifyDown(i);
    }

    void display() {
        cout << "Max-Heap: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};
int main() {
   
    MaxHeap maxH;

    int arr[] = {30, 10, 50, 20, 40};

    for (int val : arr) {
        maxH.insert(val);
    }

   
    maxH.display();  // Output: Max-Heap

    maxH.removeMax();

    maxH.display();

    return 0;
}
