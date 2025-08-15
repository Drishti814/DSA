#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//TC O(dividend)
//SC O(1)
int divide(int dividend, int divisor){
    if(dividend==divisor) return 1;
    int sum = 0; 
    int cnt = 0;
    while(sum + divisor < dividend){
        cnt++;
        sum += divisor;
    }
    return cnt;
}

//optimal
//TC O((logn)^2)
//SC O(1)
int divideOptimal(int dividend, int divisor){
    if(dividend==divisor) return 1;
    bool sign = true;
    if((dividend>=0 && divisor<0) || (dividend<0 && divisor>=0)) sign = false;
    long n = labs((long)dividend);
    long d = labs((long)divisor);
    long ans = 0;
    while(n>=d){
        int cnt = 0;
        while(n>=(d<<(cnt+1))){  //d<<(cnt+1)==d*2^(cnt+1)
            cnt++;
        }
        ans += 1L<<cnt;  //1<<cnt==2^cnt;
        n -= d*(1L<<cnt);
    }
    if(ans>=INT_MAX && sign==true) return INT_MAX;
    if(ans>=(long long)INT_MAX+1 && sign==false) return INT_MIN;
    if(sign==false) return -1*ans;
    return (int)ans;
}

int main(){
    int dividend, divisor;
    cin >> dividend;
    cin >> divisor;
    //int ans = divide(dividend,divisor);
    int ans = divideOptimal(dividend,divisor);
    cout << ans;
}