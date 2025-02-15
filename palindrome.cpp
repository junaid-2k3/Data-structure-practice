// #include <iostream>
// #include <string>
// using namespace std;

// bool is_palindrome(string str){
//     for(int i=0 ; i<(str.length())/2 ;i++){
//         if(str[i]!=str[str.length()-i-1])
//         return false;
//     }
//     return true;
// }
// int main (){
//     string demo="radar";
//     if(is_palindrome(demo)){
//         cout<<"the string is a palindrome"<<endl;
//     }
//     else
//     cout<<"not a palindrome"<<endl;

// // int strlength=demo.length();
// // int strMid=demo.length()/2;

// }

/////////88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

// two pointer approach

#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(const string &str)
{
    const char *left = &str[0];
    const char *right = &str[0] + str.length() - 1;

    while (left < right)
    {
        if (*left != *right)
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int count_frequency(const string &str, char ch)
{
    const char *ptr = str.c_str();
    int count = 0;

    while (*ptr != '\0')
    {
        if (*ptr == ch)
        {
            count++;
        }
        ptr++;
    }
    return count;
}

int main()
{
    string demo = "babab"; 
    char target_char = 'b';
    if (is_palindrome(demo))
    {
        cout << "The string is a palindrome" << endl;
    }
    else
    {
        cout << "The string is not a palindrome" << endl;
    }

    int frequency = count_frequency(demo, target_char);
    cout << "The character '" << target_char << "' appears " << frequency << " times in the string." << endl;
    return 0;
}
