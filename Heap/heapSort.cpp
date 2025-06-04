#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index 'i'
// This version builds a Max-Heap
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;           // Assume the current node is the largest
    int left = 2 * i + 1;      // Index of left child
    int right = 2 * i + 2;     // Index of right child

    // Check if left child exists and is greater than current largest
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the current node, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);     // Swap current node with the larger child
        maxHeapify(arr, n, largest);    // Recursively heapify the affected subtree
    }
}

// Function to perform Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array

    // --------------------------
    // Step 1: Build a Max-Heap
    // --------------------------
    // Start from the last non-leaf node and move upwards
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);  // Heapify each node
    }

    // --------------------------------------------
    // Step 2: Extract elements from the max-heap
    // --------------------------------------------
    // Move the root (largest) to the end one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);       // Move current root to the end
        maxHeapify(arr, i, 0);      // Call maxHeapify on the reduced heap
    }
}

// Driver code to test the heap sort algorithm
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7}; // Sample input array

    cout << "Original array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    // Call heap sort
    heapSort(arr);

    cout << "Sorted array using Heap Sort:\n";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    return 0;
}
