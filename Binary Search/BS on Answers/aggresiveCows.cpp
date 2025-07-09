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

bool canWePlace(vector<int> &a,int n, int k, int distance){
    int cowNum = 1;
    int lastCow = a[0];
    for(int i = 0;i<n;i++){
        if(a[i]-lastCow>=distance){
            cowNum++;
            lastCow = a[i];
        }
        if(cowNum==k) return true;
    }
    return false;
}

//brute force
//TC O(n*(max-min)+nlogn)
int maxOfMinDistances(vector<int> &a, int n, int k){
    sort(a.begin(),a.end());
    int maxi = findMax(a,n);
    int mini = findMin(a,n);
    for(int i = 1;i<=maxi-mini;i++){
        if(canWePlace(a,n,k,i)==true) continue;
        else  return i-1;
    }
    return -1;
}

//optimal
//TC O(n*log(max-min)+nlogn)
int maxOfMinDistancesOptimal(vector<int> &a, int n, int k){
    sort(a.begin(),a.end());
    int maxi = findMax(a,n);
    int mini = findMin(a,n);
    int ans = -1;
    int low = 1;
    int high = maxi - mini;
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlace(a,n,k,mid)==true){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
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
    int k;
    cin >> k;
    //int ans = maxOfMinDistances(a,n,k);
    int ans = maxOfMinDistancesOptimal(a,n,k);
    cout << ans;
}