#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

int findMin(vector<int> &a,int n){
    int mini = INT_MAX;
    for(int i = 0;i<n;i++){
        mini = min(a[i],mini);
    }
    return mini;
}

int findMax(vector<int> &a,int n){
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        maxi = max(a[i],maxi);
    }
    return maxi;
}

//brute force
bool countB(vector<int> &a,int n, int day, int m, int k){
    int cnt = 0;
    int numOfB = 0;
    for(int i = 0;i<n;i++){
        if(a[i]<=day){
            cnt++;
        }
        else{
            numOfB += cnt/k;
            cnt = 0;
        }
    }
    numOfB += cnt/k;
    if(numOfB==m) return true;
    else return false;
}

int minDays(vector<int> &a, int n, int m, int k){
    if(n < m*k) return -1;
    int mini = findMin(a,n);
    int maxi = findMax(a,n);
    for(int i = mini;i<=maxi;i++){
        if(countB(a,n,i,m,k)==true) return i;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int m,k;
    cin >> m;
    cin >> k;
    int ans = minDays(a,n,m,k);
    cout << ans;
}