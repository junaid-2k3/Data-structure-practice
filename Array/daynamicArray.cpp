#include <iostream>
using namespace std;

int newvalue()
{
    char ch = 'y';
    cout << "\n do you want enter new value (y/n) ? ";
    cin >> ch;
    return (ch == 'y' || ch == 'Y') ? 1 : 0;
}

void input(int *&arr, int &sz)
{
    // Allocate new memory for the growing array
    int *newArr = new int[sz + 1];
    // Copy existing elements to the new array
    for (int i = 0; i < sz; i++)
    {
        newArr[i] = arr[i];
    }
    // Add the new input to the array
    cout << "\n new value = ";
    cin >> newArr[sz];
    // Free the old memory
    delete[] arr;
    // Update the pointer and size
    arr = newArr;
    sz++;
}
int main()
{
    int *arr = nullptr; // Pointer to store the dynamically allocated array
    int sz = 0;         // Current size of the array

    while (newvalue())
    {
        input(arr, sz);
    }
    // Display the stored values
    cout << "\n values stored in your dynamic array = ";
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Free the final allocated memory
    delete[] arr;
    return 0;
}