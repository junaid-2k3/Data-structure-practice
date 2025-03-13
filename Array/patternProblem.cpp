#include <iostream>
using namespace std;
int main(){
    int input;
    cout << "Enter a number: ";
    cin >> input;
    int n = (input % 5) + 1;
    int counter=0;
    while(counter<n){
        if(counter==0){
            cout<<"*11111";
        }
        else if(counter==1){
            cout<<"**2222";
        }
        else if(counter==2){
            cout<<"***333";
        }
        else if(counter==3){
            cout<<"****44";
        }
        else if(counter==4){
            cout<<"*****5";
        }
        else if(counter==5){
            cout<<"******";
        }
        counter++;
        cout<<endl;
    }
}