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

//without using lower and upper bound
int firstOccurence(vector<int> &a, int n, int target){
    int ans = -1;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] == target){
            ans = mid;
            high = mid-1;
        }
        else if(a[mid] > target) high = mid - 1;
        else low = mid+1;
    }
    return ans;
}

int lastOccurence(vector<int> &a, int n, int target){
    int ans = -1;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] == target){
            ans = mid;
            low = mid+1;
        }
        else if(a[mid] > target) high = mid - 1;
        else low = mid+1;
    }
    return ans;
}

pair<int,int> firstAndLast(vector<int> &a, int n, int target){
    int f = firstOccurence(a,n,target);
    if(f==-1) return {-1,-1};
    int l = lastOccurence(a,n,target);
    return {f,l};
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
    pair<int,int> ans;
    ans = firstAndLastElement(a,n,target);
    //cout << ans.first << " " << ans.second;

    pair<int,int> s;
    s = firstAndLast(a,n,target);
    cout << s.first << " " << s.second;
}