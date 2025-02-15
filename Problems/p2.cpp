// we have to find the duplicates in a list and then remove the duplicates form the list 
// printing the new list , with only single occurance of all the elements 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void display(vector<int> vec){
    for(int c : vec){
        cout<<c<<" ";
    }
}

void find_duplicate(vector<int> &vec){
    for(int i=0; i<vec.size() ;i++){
        for(int j=0 ; j<vec.size() ; j++){
            if( i!=j && vec[i]==vec[j]){
                vec.erase(vec.begin()+j);
            }

        }
    }
}
int main(){
    vector<int>list={1,3,5,6,3,2,6,9,0,1};
    cout<<" original :"<<endl;
    display(list);
    find_duplicate(list);
    cout<<"\n after removing duplicates"<<endl;
    display(list);
}