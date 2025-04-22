#include <iostream>
#include <string>
#include <limits>
using namespace std;
// how to validate an integer in cPP

void input_validation(int &a, string des) {
    while (true) {
        cout << des << endl;
        cin >> a;
        if (cin.fail()) {
            cout << "Input is invalid" << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input
        } else {
            return;
        }
    }
}
template<typename T>  /// this needs a fix  ,it is taking all kinds of input 
T input_validation1(){
    T a;
    while(true){
        cout<<"enter a T\n";
        cin>>a;
        if(cin.fail()){
            cout<<"invalid input ! please input c "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(),'\n');
        }else{
            return a;
        }
    }
}
int main(){
    int a=input_validation1<int>();
    
}
