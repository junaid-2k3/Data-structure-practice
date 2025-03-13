#include <iostream>
using namespace std;

int main(){
    int rows,cols;
    cout<<"enter rows and column for the materx :"<<endl;
    cin>>rows;cout<<endl;
    cin>>cols;

    int** p2array=new int*[rows];
    for(int i= 0;i<rows ; i++){
        p2array[i]=new int[cols];
    }
    //initialization 
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> p2array[i][j];
        }
    }
        //printing 
        cout << "The 2D array is:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << p2array[i][j] << " ";
            }
            cout << endl;
        }

        // freeing of the dynamically allocated array 
        for(int i = 0 ;i<rows ;i++){
            delete[] p2array[i];
        }
        delete[] p2array;
        return 0;
}