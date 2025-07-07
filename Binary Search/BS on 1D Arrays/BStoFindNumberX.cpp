#include<iostream>
#include<vector>
using namespace std;

//brute force - linear
//optimal - BS
//only applicable in sorted search space
//time complexity - O(logn)
//overflow case if low = high = INT_MAX then mid = (INT_MAX+INT_MAX)/2 which exceeds int
//use long long low,high or take mid = low + (high - low)/2

//Iterative Approach
int binarySearchIterative(vector<int> &a, int n, int target){
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] == target) return mid;
        else if(target > a[mid]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

//Recusive Approach
int binarySearchRecursive(vector<int> &a, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low + high)/2;
    if(a[mid] == target) return mid;
    else if(target > a[mid]) return binarySearchRecursive(a,mid+1,high,target);
    return binarySearchRecursive(a,low,mid,target);
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
    //int index = binarySearchIterative(a,n,target);
    int index = binarySearchRecursive(a,0,n-1,target);
    cout << index;
}