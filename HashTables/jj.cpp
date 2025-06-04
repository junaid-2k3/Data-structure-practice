#include <iostream>
#include <list>
using namespace std;

class hashTable{
    private :
    int key;
    int index;
    int sizeOfTable;
    list<int>* table;

    int hashFunction(int key)
    {
    return key % sizeOfTable;
    }

    void insert(int key){
        this->key=key; // key that the user has entered 
        index=hashFunction(key);
    }
    public:

};
