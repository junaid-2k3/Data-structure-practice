#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int size, int* arr) {
    int n = size;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // ✅ Reset for each outer loop
        for (int j = 0; j < n - i - 1; j++) {  // ✅ Fixed increment
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            cout << "The array is sorted.\n";
            return;
        }
    }
}


int main() {
    int arr[7] = {7, 3, 4, 51, 2, 1, 5};  // ✅ Size matches input
    bubbleSort(7, arr);  // ✅ Correct size

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
