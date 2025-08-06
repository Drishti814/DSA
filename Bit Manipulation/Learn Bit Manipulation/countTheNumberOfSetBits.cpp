#include<iostream>
#include<algorithm>
using namespace std;

//TC O(logn)
int numberOfSetBits(int n){
    int cnt = 0;
    while(n > 1){
        cnt += n&1;  //cnt++ if n%2==1
        n = n>>1;   //n = n/2;
    }
    if(n==1) cnt+=1;
    return cnt;
}

//TC O(number of set bits)
int numOfSetBits(int n){
    int cnt = 0;
    while(n!=0){
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    int ans = numberOfSetBits(n);
    //int ans = numOfSetBits(n);
    cout << ans;
}