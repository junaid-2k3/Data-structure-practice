// 5 persons are standing in a circle ,one person is eliminated randomly at a time ,show //the person that is eliminated 
// solve the question through recursion 

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int randomNum(){
    srand(time(0));
   int ranNum1=(rand()%5);
return ranNum1;
}
void recursiveElimination(vector<string> &vec){
    if(vec.size()==1){
        cout<<vec.front()<<" is the surviver "<<endl;
        return;
    }
    int randomN=rand()%vec.size();
    cout<<vec.at(randomN)<<" is eliminated" <<endl;
    vec.erase(vec.begin()+randomN);
    recursiveElimination(vec);
}
int main(){
    vector<string>friends={"ali","sudais","kamran","haider","jameel"};
    recursiveElimination(friends);
}

