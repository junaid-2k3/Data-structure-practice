// Partial initialization of a 2D array occurs when you provide values for only some elements of the array, while the rest are automatically initialized to zero (for non-class types) or the default value for the given type

#include <iostream>
using namespace std;

int main() {
    // Partial initialization of a 2D array
    int arr[3][4] = {
        {1, 2},         // First row: 1, 2, 0, 0
        {3},            // Second row: 3, 0, 0, 0
        {0}             // Third row: 0, 0, 0, 0
    };

    // Displaying the array
    cout << "Array elements:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


//When initializing a multi-dimenssional array sequentially, the compiler treats it as a single contiguous block of memory and assigns the values in row-major order (i.e., filling one row completely before moving to the next).

#include <iostream>
using namespace std;

int main() {
    // Sequential initialization of a 3D array
    int arr[2][2][3] = {
        1, 2, 3,   // First "row" of the first 2D layer
        4, 5, 6,   // Second "row" of the first 2D layer
        7, 8, 9,   // First "row" of the second 2D layer
        10, 11, 12 // Second "row" of the second 2D layer
    };

    // Printing the 3D array elements
    cout << "3D Array Elements:" << endl;
    for (int i = 0; i < 2; i++) {         // Loop through layers
        cout << "Layer " << i + 1 << ":" << endl;
        for (int j = 0; j < 2; j++) {     // Loop through rows
            for (int k = 0; k < 3; k++) { // Loop through columns
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
    