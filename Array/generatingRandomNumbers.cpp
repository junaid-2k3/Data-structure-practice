// for generating random numbers we need two libraries 1)cstdlib and 2)ctime
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// we can generate a psuedo random number with the help of rand() functon but it will not generte a random number for every call
// to solve this prolem we are gonna use laptop time to help us generte random numbers that  is why we included the ctime lib
int main(){
    srand(time(0));   //<---- this initialize a random seed

    for(int i=0 ; i<10 ;i++){
    cout<<rand()%((30-10+1)+10);cout<<endl;
    }
}