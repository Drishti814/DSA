#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<map>
using namespace std;

//xor from 1 to n
//brute force - loop i from 1 to n and doing xor = xor ^ i
//TC O(n)
//SC O(1)

//optimal
//TC O(1)
//SC O(1)
int xorTillN(int n){
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
    return n;
}

//xor from L to R
//brute force - loop i from L to R and doing xor = xor ^ i
//TC O(R-L+1)
//SC O(1)

//optimal
//TC O(1)
//SC O(1)
int xorInGivenRange(int L, int R){
    int xorL = xorTillN(L);
    int xorR = xorTillN(R);
    int ans = xorL ^ xorR;
    return ans;
}


int main(){
    int n;
    cin >> n;
    int L, R;
    cin >> L >> R;
    //int ans = xorTillN(n);
    int ans = xorInGivenRange(L,R);
    cout << ans;
}