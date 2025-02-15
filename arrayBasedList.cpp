#include <iostream>
using namespace std;

class ArrayList
{
    int size;   // total capacity of the array
    int length; // number of elements
    int *arr;
    int *curr;

public:
    ArrayList(int size)
    {
        this->size = size;
        length = 0;
        arr = new int[size];
        //     for (int i = 0; i < size; ++i) {
        //     arr[i] = rand() % (20 - 2 + 1) + 2;
        // }
        curr = NULL;
    }

    void start() // this method set the curr pointer to point to the first element of the array
    {

        curr = arr;
    }

    void tail() // this method set the curr pointer to point to the last element of the array
    {

        curr = arr + length - 1;
    }

    void back() // This method is used to navigate to the previous element in the list.
    {

        curr--;
    }

    void next() // This method is used to navigate to the next element in the list.
    {
        curr++;
    }

    void insert(int pos, int val)
    {
        if (size == length)
        {
            cout << "list is full" << endl;
        }
        else if (pos < 1 || pos > length + 1)
        {
            cout << "invalid position" << endl;
        }
        else
        {
            tail();
            for (int i = length; i >= pos; i--)
            {
                *(curr + 1) = *curr;
                back();
            }
            *(curr + 1) = val;
            length++;
        }
    }

    void printList()
    {
        start();
        for (int i = 1; i <= length; i++)
        {
            cout << *curr << " ";
            next();
        }
        cout << endl;
    }

    void remove(int pos){
        if (pos < 1 || pos > length + 1)
            {
                cout << "invalid position" << endl;
            }
            else{
                     start();
                curr+=pos;
                for(int i=length ;i>=pos ;i--)
                *(curr)=*(curr + 1);
            }
    }



};



int main()
{
    ArrayList l(5);
    l.insert(1, 2);
    l.printList();
    l.insert(2, 3);
    l.printList();
    l.insert(3, 4);
    l.insert(4,5);
    l.printList();
    cout<<endl;
    l.remove(1);
    l.printList();
    l.remove(2);
}
