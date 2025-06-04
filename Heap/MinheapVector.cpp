#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i)  { return (i - 1) / 2; }
    int left(int i)    { return 2 * i + 1; }
    int right(int i)   { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void removeMin() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }
        cout << "Removing min: " << heap[0] << endl;
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
        cout << "Min-Heap: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};
int main() {
    MinHeap minH;


    int arr[] = {30, 10, 50, 20, 40};

    for (int val : arr) {
        minH.insert(val);
       
    }

    minH.display();  // Output: Min-Heap
 

    minH.removeMin();

    minH.display();
    

    return 0;
}
