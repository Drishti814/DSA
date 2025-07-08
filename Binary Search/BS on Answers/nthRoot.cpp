#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

//brute force
//O(n)
int nthRoot(int num,int n){
    int ans = -1;
    for(int i = 0;i<=num;i++){
        if(pow(i,n)<=num) ans = i;
        else break;
    }
    return ans;
}

//optimal
//O(logn)
int nthRootOptimal(int num,int n){
    int ans = -1;
    int low = 0;
    int high = num-1;
    while(low<=high){
        long long mid = (low+high)/2;
        if(pow(mid,n)==num){
            return mid;
        }
        else if(pow(mid,n)>num){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans; 
}

int main(){
    int num;
    cin >> num;
    int n;
    cin >> n;
    //int ans = nthRoot(num,n);
    int ans = nthRootOptimal(num,n);
    cout << ans;
}