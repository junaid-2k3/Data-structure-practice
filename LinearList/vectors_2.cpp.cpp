// vectors are more like arrays but having the functionality of dynamic memory allocation 
// for vector we have to include the STL library of vectors <vectors>
// there are three ways to initiate a vector ,
//(1) vector<int>vec;
//(2) vector<int>vec={1,2,3};
//(3) vector<int>vec(3,0);

#include<iostream>
#include <vector>
using namespace std;
int main(){
//     vector<int>vec={1,2,3,4,5};
//     vector<int>vec2(3,0);

//     for (int value : vec){
//         cout<<value<<"  ";
//     }
//     for (int value : vec2){
//         cout<<value<<"  ";
//     }
// cout<<endl;
//     cout<<vec.size()<<endl;
//     cout<<endl;
//     cout<<vec2.size()<<endl;
//     vec.push_back(6); /// push-back function add an element to the end of the  the vector
//      for (int value : vec){
//         cout<<value<<"  ";
//     }
//     cout<<endl;
//     cout<<vec.size()<<endl;
//     cout<<endl;
//     vec.pop_back();
//     cout<<endl;
//      /// push-back function add an element to the end of the  the vector
//      for (int value : vec){
//         cout<<value<<"  ";
//     }
//     cout<<endl;
//     vec.pop_back();
//      for (int value : vec){
//         cout<<value<<"  ";
//     }
//     cout<<endl<< " ******"<<endl;
//      cout<<"front :"<<vec.front();cout<<endl;
//      cout<<"back";
//     cout<<vec.back();cout<<endl;
//     cout<<vec.at(2)<<endl;

vector <int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(2);
cout<<vec.size();cout<<endl;
cout<<vec.capacity();
vec.push_back(4);
vec.push_back(5);
cout<<endl;
cout<<vec.size();cout<<endl;
cout<<vec.capacity();





    return 0;

}