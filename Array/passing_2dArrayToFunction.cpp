// When passing a 2D array with fixed dimensions, you must specify the number of columns (but not the rows) in the function parameter.
// it is compulsory to allways mention the colomn number in defining a funcion ,row number maybe skiped .
#include <iostream>
using namespace std;

// Function to print a 2D array
void printArray(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printArray(matrix, 2); // Pass the array and the number of rows
    return 0;
}

////*************************************************************** */

// You can pass a 2D array using a pointer. This requires knowledge of the number of columns so that the memory layout can be interpreted correctly.

#include <iostream>
using namespace std;

// Function to print a 2D array using a pointer
void printArray(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(arr + i * cols + j) << " "; // Access elements using pointer arithmetic
        }
        cout << endl;
    }
}

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}}; 
    printArray((int*)matrix, 2, 3); // Cast the 2D array to a pointer
    return 0;
}
