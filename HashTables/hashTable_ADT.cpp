#include <iostream>
#include <conio.h>  // input output 
#include <list>

using namespace std;
const short int EXIT=0, INSERTION=1 ,DELETION=2, SEARCH=3,DISPLAY=4;
class HashTable{

    private :

    int key; // the actual data that you will take form the user 
    int sizeOfTable;// fix size of hashtable 
    int index; // index of hashtable 
    list<int>*table; // table is pointer to a linked list that store an int     
    int hashFunction(int value){
        key=value;
        return key%sizeOfTable; // generate index and return it 
    }
    void insertValue(int value){
        key=value;
        index=hashFunction(key);
        table[index].push_back(key); // linked list ke last mai generated index per key ko insert karta hai 
    }
    bool findValue(int value){
        key=value;
        index=hashFunction(key);
        for(auto item : table[index]){ // range loop , for each loop 
            if(item == key)     // ye loop sirf aik index pe pari linked list ko traverse karta hai na ke pure hashtable ko
                return true;
        }
            return false;
    }
    void deleteValue(int value){
            key=value;
            index=hashFunction(key);
            table[index].remove(key);
    }
    public :
    
    int choice;
    HashTable():key(0),sizeOfTable(10),table(nullptr),index(0){
        cout<<"\n enter the size of the hashtable "<<endl;
        cin>>sizeOfTable;
        table = new list<int>[sizeOfTable];
    }

    void insertValue(){
        cout<<"\n enter a value for insertion "<<endl;
        cin>>key;
        insertValue(key);
        cout<<"\n insertion successful"<<endl;
    }
    void findValue(){
        cout<<"\n enter value to search"<<endl;
        cin>>key;
        if(findValue(key)){
            cout<<"\n value found at index : "<<index;
        }else{
            cout<<"\n value not found"<<endl;
        }
    }
    void deleteValue(){
        cout<<"ente value for deletion "<<endl;
        cin>>key;
    }
    void displayHashTable(){
        cout<<"\n value in the hash table : ";
        for (int i=0 ; i<sizeOfTable ; i++){
            cout<<"\n index "<<i<<" = ";
            for(auto value : table [i]){
                cout<<value<<"->";
                cout<<"end of list ";
            }
            cout<<"\n end of hash table \n ";
        }
    }
    void displayMenu(){
        cout<<"******************* hast table adt *********************"<<endl;
        cout<<"0 for exit "<<endl;
        cout<<"1 for insertion "<<endl;
        cout<<"2 for deletion "<<endl;
        cout<<"3 for searching "<<endl;
        cout<<"4 for display"<<endl;
        cin>>choice;
    }
    void clearMenu(){
        if(choice){
            cout<<"\n press any key to continue "<<endl;
            _getch();
            system("cls");
        }
    }

};
int main(){
HashTable table1;
do{
    table1.displayMenu();
    switch(table1.choice){
        case INSERTION : table1.insertValue();
            break;
        case DELETION : table1.deleteValue();
            break;
        case SEARCH : table1.findValue();
            break;
        case DISPLAY : table1.displayHashTable();
            break;
        case EXIT : break;
        default : cout<<"\n invalid choice ";
    }
    table1.clearMenu();
}while(table1.choice);
cout<<endl<<endl;
}