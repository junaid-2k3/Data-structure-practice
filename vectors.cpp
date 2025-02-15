#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int> vec){
    for(int element : vec){
        cout<<element<<endl;
    }
}
void display2d(vector<vector<int>> vec){
    for(const auto& row : vec){
        cout<<endl;
    for(int element : row ){
        cout<<element;
    }
    }
}
int main(){
    vector<int> val={1,3,4};
    // 2d vector or vector within a vector 
    vector<vector<int>> matrix_vector={{1,2,3},{4,5,6}};   
    // for(const auto& row :matrix_vector){
    //     cout<<endl;
    //     for(int cell : row){
    //         cout<<cell;
    //     }
    // }

    vector<vector<int>> matrix(3,vector<int>(3,0));
    display(val);
    display2d(matrix);

    
    // vector<int>v1;
    // v1={4,2,5,3,6,7,3,1};
    // sort(v1.begin(),v1.end());// sort in ascending order 
    // sort(v1.rbegin(),v1.rend()); // sort in decsending order 
    // display(v1);
    // reverse(v1.begin(),v1.end());
    // cout<<endl;
    // display(v1);

    // v1.push_back(10);
    // v1.push_back(20);
    // v1.push_back(30);
    // v1.push_back(40);
    // v1.push_back(50);
    // display(v1);
    // cout<<endl;
    // v1.insert(v1.begin()+2,11);
    // v1.insert(v1.begin()+2,99);
    // v1.erase(v1.begin()+2);
    // v1.erase(v1.begin()+2);
    // display(v1);
    // cout<<v1.capacity();cout<<endl;
    // cout<<v1.size();
    //vector<int> a = {1, 2, 3}, b = {4, 5, 6};
// a.swap(b); // a becomes {4, 5, 6}, b becomes {1, 2, 3}


    
}