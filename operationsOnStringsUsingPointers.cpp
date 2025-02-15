#include <iostream>
#include <string>
// #include <cctype>
using namespace std;

void string_ftn(string &input){
    
    char key;
    int key_index;
    cout<<"input the character you want to find :"<<endl;
    cin>>key;
    for(int i=0 ; i<input.size() ; i++){
        if(input[i]==key){
            cout<<"character exsist"<<endl;
            key_index=i;
        }
        else
        cout<<"character not found"<<endl;
    }
    char key2;
    cout<<"enter the element to be placed at that place "<<endl;
    cin>>key2;
    input[key_index]=key2;
}
void print_string(string input){
    for(char c :input){
        cout<<c;
    }
}
void capitalize_string(string &input){
    for(int i=0 ; i<input.size() ; i++){
        input[i]=toupper(input[i]);
    }
}
int main(){
string input;
cout<<"enter a string :"<<endl;
cin>>input;
capitalize_string(input);

string_ftn(input);
cout<<endl;
print_string(input);

}