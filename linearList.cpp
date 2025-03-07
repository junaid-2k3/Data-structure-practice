#include <iostream>
using namespace std;

// Interface class for Linear List
class LinearList
{
public:
    virtual void insert() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
    virtual void display() const = 0;
    virtual int size() const = 0;
    virtual ~LinearList() {} // Virtual destructor
};

// Concrete implementation of Linear List using Array
class ArrayLinearList : public LinearList
{
private:
    int *arr;        // Pointer to dynamically allocated array
    int capacity;    // Maximum capacity of the array
    int currentSize; // Current number of elements in the array

public:
    // Constructor
    ArrayLinearList(int capacity) : capacity(capacity), currentSize(0)
    {
        arr = new int[capacity];
    }

    // Destructor
    ~ArrayLinearList()
    {

        delete[] arr;
    }

    // Insert element at a specific position
    void insert() override
    {
        if (currentSize == capacity)
        {
            cout << "Error: The list is full. Cannot insert element.\n";
            return;
        }

        int element, position;
        cout << "Enter the element to insert: ";
        cin >> element;
        cout << "Enter the position to insert at: ";
        cin >> position;

        if (position < 0 || position > currentSize)
        {
            cout << "Error: Invalid position.\n";
            return;
        }

        // Shift elements to the right
        for (int i = currentSize; i > position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        currentSize++;
    }

    // Remove element at a specific position
    void remove() override
    {
        if (currentSize == 0)
        {
            cout << "Error: The list is empty. Cannot remove element.\n";
            return;
        }

        int position;
        cout << "Enter the position to remove: ";
        cin >> position;

        if (position < 0 || position >= currentSize)
        {
            cout << "Error: Invalid position.\n";
            return;
        }

        // Shift elements to the left
        for (int i = position; i < currentSize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        currentSize--;
    }

    // Update the value of an element at a specific position
    void update() override
    {
        if (currentSize == 0)
        {
            cout << "Error: The list is empty. Cannot update element.\n";
            return;
        }

        int position, newValue;
        cout << "Enter the position to update: ";
        cin >> position;
        cout << "Enter the new value: ";
        cin >> newValue;

        if (position < 0 || position >= currentSize)
        {
            cout << "Error: Invalid position.\n";
            return;
        }

        arr[position] = newValue;
    }

    // Display the elements in the list
    void display() const override
    {
        if (currentSize == 0)
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "List elements: ";
        for (int i = 0; i < currentSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Get the current size of the list

    int size() const override
    {
        return currentSize;
    }
};

// Driver program to test the Linear List ADT
int main()
{
    int capacity;
    cout << "Enter the capacity of the list: ";
    cin >> capacity;

    ArrayLinearList list(capacity);

    // Menu-driven program
    int choice;
    do
    {
        cout << "\n--- Linear List Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Remove Element\n";
        cout << "3. Update Element\n";
        cout << "4. Display List\n";
        cout << "5. Get List Size\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            list.insert();

            break;
        case 2:
            list.remove();
            break;
        case 3:
            list.update();
            break;
        case 4:
            list.display();
            break;
        case 5:
            cout << "Current size of the list: " << list.size() << endl;
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}