#include <iostream>
using namespace std;
bool linear_search_in_2d(int matrix[][3],int row ,int col, int target){
    for(int i=0 ; i<row ;i++){
        for(int j=0 ;j<col ; j++){
            if(matrix[i][j]==target){
                return true;
            }

        }
    }
    return false;
}
int main(){
    int rows=4;
    int col=3;
    // it is necessary to explicitly declare the size of 2nd dimenssion of the array in both the array declaration and in function definintion 
    int matrix[4][3]={{1,2,3},{7,8,9},{17,18,19},{27,28,29}};
    if(linear_search_in_2d(matrix,rows,col,19)){
        cout<<"element found"<<endl;
    }
    else
    cout<<"element not found"<<endl;
    return 0;
}
