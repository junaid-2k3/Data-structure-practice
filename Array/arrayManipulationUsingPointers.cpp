
#include <iostream>
using namespace std;

int main()
{

   int arr[] = {1, 2, 3, 4, 5};
   int *ptr = arr + 2;
   ptr[-1] = *ptr + *(ptr + 1);   // with pointers we can use negative indexing sinse it only does pointer arithmetic to derefer the element
   for (int i = 0; i < 5; i++)
   {
      cout << arr[i] << " ";
}

///88888888888888888888888888
#include <iostream>
using namespace std;

int main()
{

   int matrix[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},{{1, 2, 3, 4}, {5, 6, 7, 8}, {3, 1, 288, 22}}};
   int *p = matrix[0][0];
   // *(p + 9) = *(*(matrix) + 3);
   // cout << matrix[2][2]; cout<<endl;
   cout<<*(*(*(matrix+1)+2)+2);
}
    
}
