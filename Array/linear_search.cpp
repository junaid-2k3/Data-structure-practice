#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int linearSearch(int array[], int size ,int target);   // prototype
  
int main(){
  
    int size=10;
    int array[size]={34,65,89,23,54,11,44,39,64,5,};
    const int target=11;
    cout<< linearSearch(array,size ,5);
}
int linearSearch(int array[], int size ,int target){
    for (int i=0 ; i<10 ;i++){
    if (array[i]==target){
        return i;
    }
}
    return -1;

    }

