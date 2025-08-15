#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int numOfSetBits(int n){
    int cnt = 0;
    while(n!=0){
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}

int minBitFlips(int start, int goal){
    int ans = start^goal;
    int cnt = numOfSetBits(ans);
    return cnt;
}

int main(){
    int start,goal;
    cin >> start >> goal;
    int ans = minBitFlips(start,goal);
    cout << ans;
}