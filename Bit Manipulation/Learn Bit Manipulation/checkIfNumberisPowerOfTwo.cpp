#include<iostream>
#include<algorithm>
using namespace std;

bool numPowOfTwo(int n){
    if(n<=0) return false;
    int ans = n&(n-1);
    if(ans==0) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    bool ans = numPowOfTwo(n);
    if(ans) cout << "Number is power of two ";
    else cout << "Number is not power of two ";
}