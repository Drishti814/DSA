#include<iostream>
#include<algorithm>
using namespace std;

//using left shift operator
bool checkSetOrNot(int n, int i){
    if ((n&(1<<i))!=0) return true;
    else return false;
}

//using left shift operator
bool checkSet(int n, int i){
    if (((n>>i)&1)==0) return false;
    else return true;
}

int main(){
    int n;
    cin >> n;
    //bool ans = checkSetOrNot(n,2);
    bool ans = checkSet(n,2);
    if(ans==true) cout << "bit is set";
    else cout << "bit is not set";
}