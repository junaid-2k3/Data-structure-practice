// patterens using for loops 
//1) the outer loop will always be the number of rows
//2) the inner loop will always be the number of cols

/// pattern no 1

// 1234
// 1234
// 1234
// 1234

#include <iostream>
using namespace std;

// int main (){
//      int n=4;
//      for (int i=1 ; i<=n ; i++){
//         char ch='A';
//         for (int j=1 ;j<=n ; j++){
//             cout<<ch<<" ";
//             ch=ch+1;
//         }
//         cout<< endl;
//      }
// }
// ************************************************************

// pattern no 2
// 123
// 456
// 789

int main(){
    int n=3;
    for (int i=0 ; i<n ;i++){

        for (int j=1 ;j<=n ;j++){
            cout<<i+j<<" ";
        }
        cout<<endl;
    }
}