#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long MaxPairwiseProduct(vector<int> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = max(max_product, (long long)numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

// long long MaxPairwiseProductFast(const vector<int> numbers)
// {
//     int n = numbers.size();
//     int index1 = -1;
//     for (int i = 0; i < n; ++i)
//     {
//         if (index1 == -1 || numbers[i] > numbers[index1])
//         {
//             index1 = i;
//         }
//     }
//     int index2 = -1;
//     for (int j = 0; j < n; ++j)
//     {
//         if ((j != index1) && ((index2 == -1) || (numbers[j] > numbers[index2])))
//             index2 = j;
//         return ((long long)(numbers[index1])) * numbers[index2];
//     }
// }
long long MaxPairwiseProductFast(const vector<int>& numbers)
{
    int n = numbers.size();
    
    // Ensure at least 2 elements exist
    if (n < 2) return 0;

    int index1 = 0;
    int index2 = -1;

    // Find the index of the maximum element
    for (int i = 1; i < n; ++i)
    {
        if (numbers[i] > numbers[index1])
        {
            index1 = i;
        }
    }

    // Find the index of the second maximum element
    for (int i = 0; i < n; ++i)
    {
        if (i != index1 && (index2 == -1 || numbers[i] > numbers[index2]))
        {
            index2 = i;
        }
    }

    return (long long)numbers[index1] * numbers[index2];
}

int main()
{
    // while (true)
    // {
    //     int n=rand() % 4 + 2;
    //     cout << n << endl;
    //     vector<int> a;
    //     for (int i = 0; i < n; ++i)
    //     {
    //         a.push_back(rand() % 10);
    //     }
    //     for (int i=0; i<n ;++i){
    //         cout<<a[i]<< ' ';
    //     }
    //     cout<<endl;
    //     long long res1 = MaxPairwiseProduct(a);
    //     long long res2 = MaxPairwiseProductFast(a);
    //     if(res1 != res2){
    //         cout<<"wrong answer :"<<res1 <<' '<<res2 <<endl;
    //         break;
    //     }
    //     else{
    //         cout<<"ok"<<endl;
    //     }
    // }
    int n;
    cin>>n;
    vector<int>numbers(n);
    for(int i= 0;i<n ;++i){
        cin>>numbers[i];
    }
    long long result= MaxPairwiseProductFast(numbers);
    cout<<result<<endl;
    return 0;
}
//////
