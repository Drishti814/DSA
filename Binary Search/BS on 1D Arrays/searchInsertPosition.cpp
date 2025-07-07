#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//lower bound will give the insert position of a new integer in a sorted array at its sorted position if not present if present will return the index

//time complexity - O(logn)

int insertPosition(vector<int> &a, int n, int target){
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
    int index = insertPosition(a,n,target);
    cout << index;
}