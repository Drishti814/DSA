#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

int powNum(int i, int num, int n){
    long long ans = 1;
    for(int j = 1;j<=n;j++){
        ans *= i;
        if(ans>num) return 2;
    }
     if(ans==num) return 1;
     return 0;
}

//brute force
//O(num)
int nthRoot(int num,int n){
    int ans = -1;
    for(int i = 0;i<=num;i++){
        if(powNum(i,num,n)==1) return i;
        else if(powNum(i,num,n)==2) break;
    }
    return ans;
}

//optimal
//O(log(num))
int nthRootOptimal(int num,int n){
    int ans = -1;
    int low = 0;
    int high = num;
    while(low<=high){
        long long mid = (low+high)/2;
        if(powNum(mid,num,n)==1){
            return mid;
        }
        else if(powNum(mid,num,n)==2){
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
    int ans = nthRoot(num,n);
    //int ans = nthRootOptimal(num,n);
    cout << ans;
}