#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lowerBound(vector<int> &a, int n, int target){
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

int upperBound(vector<int> &a, int n, int target){
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

//TC O(2logn)
pair<int,int> firstAndLastElement(vector<int> &a, int n, int target){
    int lb = lowerBound(a,n,target);
    if(lb == n || a[lb] != target){
        return {-1,-1};
    }
    int ub = upperBound(a,n,target);
    return {lb,ub-1};
}

int occurenceCount(vector<int> &a, int n, int target){
    pair<int,int> ans;
    ans = firstAndLastElement(a,n,target);
    if(ans.first==-1) return 0;
    return ans.second - ans.first + 1;
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
    int ans = occurenceCount(a,n,target);
    cout << ans;
}