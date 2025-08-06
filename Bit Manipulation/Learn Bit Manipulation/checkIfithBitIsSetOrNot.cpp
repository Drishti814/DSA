#include<iostream>
#include<algorithm>
using namespace std;

string convertToBinary(int n){
    if(n==0) return "0";
    string s = "";
    while(n != 1){
        if(n%2==1) s+='1';
        else s+='0';
        n = n/2;
    }
    s+='1';
    reverse(s.begin(),s.end());
    return s;
}

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