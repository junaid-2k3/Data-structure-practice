#include <iostream>
using namespace std;
void display(char *s)
{
    while(*s!='\0'){
        
        cout << *s << endl;
        s++;
    
    }
}
int main()
{
    char word[] = "Pakistan";
    display(word);
}