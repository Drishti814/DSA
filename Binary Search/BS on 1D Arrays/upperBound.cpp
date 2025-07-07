#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//time complexity - O(logn)

//Iterative Approach
int upperBoundIterative(vector<int> &a, int n, int target){
    int ans = n;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] > target){
            ans = mid;
            high = mid-1;
        } 
        else low = mid+1;
    }
    return ans;
}

//Recusive Approach
int upperBoundRecursive(vector<int> &a, int low, int high, int target){
    int ans = a.size();
    if(low > high) return ans;
    int mid = (low + high)/2;
    if(a[mid] > target){
        ans = mid;
        return min(mid,upperBoundRecursive(a,low,mid-1,target));
    }
    else return upperBoundRecursive(a,mid+1,high,target);
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
    //int index = upperBoundIterative(a,n,target);
    //int index = upperBoundRecursive(a,0,n-1,target);
    //cout << index;

    //direct function
    auto ub = upper_bound(a.begin(),a.end(),target);
    if(ub != a.end()){
        cout << ub - a.begin();
    }
}