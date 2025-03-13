#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int const Week=4;
int const days=7;
int arrtemp[Week][days];

void populateArray(int arr[Week][days]){
    srand(time(0));
        for(int i=0 ; i<Week ;i++){
            for(int j=0 ; j<days ;j++){
           arr[i][j]=rand()%((30-10+1)+10);
        }
    }


}
void displayArray(int arr[Week][days]){
    for(int i=0 ;i<Week ;i++){
        for(int j=0 ; j<days ;j++){
            cout<<arr[i][j];cout<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    populateArray(arrtemp);
    displayArray(arrtemp);

}