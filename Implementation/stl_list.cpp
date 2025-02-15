#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> myList = {10, 20, 30, 40};

    myList.push_front(5);  // {5, 10, 20, 30, 40}
    myList.push_back(50);  // {5, 10, 20, 30, 40, 50}

    myList.pop_front();    // {10, 20, 30, 40, 50}
    myList.pop_back();     // {10, 20, 30, 40}

    list<int>::iterator it = myList.begin();
    advance(it, 2);        // Move iterator to 3rd element (0-based index)
    myList.insert(it, 25); // {10, 20, 25, 30, 40}

    myList.remove(20);     // Removes 20 from the list

    myList.reverse();      // {40, 30, 25, 10}

    myList.sort();         // {10, 25, 30, 40}

    cout << "List elements: ";
    for (int num : myList) {
        cout << num << " ";
    }

    return 0;
}
