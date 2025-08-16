#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

//optimal
//TC O(logn)
//SC O(1)
double myPow(double x, int n){
    long long m = n;
    if(m < 0) m = -m;
    double ans = 1; 
    while(m>0){
        if(m%2==1){
            ans = ans*x;
            m = m-1;
        }
        else{
            m = m/2;
            x = x*x;
        }
    }
    if(n<0) ans = (double)1/ans;
    return ans;
}

int main(){
    double x;
    int n;   //x^n
    cin >> x >> n;
    double ans = myPow(x,n);
    cout << ans;
}