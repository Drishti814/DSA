#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//only applicable in sorted search space
//time complexity - O(logn)
//overflow case if low = high = INT_MAX then mid = (INT_MAX+INT_MAX)/2 which exceeds int
//use long long low,high or take mid = low + (high - low)/2

//Iterative Approach
int lowerBoundIterative(vector<int> &a, int n, int target){
    int ans = n;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] >= target){
            ans = mid;
            high = mid-1;
        } 
        else low = mid+1;
    }
    return ans;
}

//Recusive Approach
int lowerBoundRecursive(vector<int> &a, int low, int high, int target){
    int ans = a.size();
    if(low > high) return ans;
    int mid = (low + high)/2;
    if(a[mid] >= target){
        ans = mid;
        return min(mid,lowerBoundRecursive(a,low,mid-1,target));
    }
    else return lowerBoundRecursive(a,mid+1,high,target);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int target;
    cin >> target;
    //int index = lowerBoundIterative(a,n,target);
    //int index = lowerBoundRecursive(a,0,n-1,target);
    //cout << index;
    //direct function
    auto lb = lower_bound(a.begin(),a.end(),target);
    if(lb != a.end()){
        cout << lb - a.begin();
    }
}