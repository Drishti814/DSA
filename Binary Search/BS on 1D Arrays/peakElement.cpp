#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//TC O(n)
int peakElement(vector<int> &a,int n){
    for(int i = 0;i<n;i++){
        if((i==0 || a[i]>a[i-1]) && (i==n-1 || a[i]>a[i+1])){
            return i;
        }
    }
    return -1;
}

//optimal
//TC O(logn)
int peakElementOptimal(vector<int> &a,int n){
    if(n==1) return 0;
    if(a[0] > a[1]) return 0;
    if(a[n-1] > a[n-2]) return n-1;
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = (low + high)/2;
        if(a[mid] > a[mid-1] && a[mid] > a[mid+1]){
            return mid;
        }
        else if(a[mid] > a[mid-1]) low = mid + 1;
        else if(a[mid] > a[mid+1]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
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
    //int index = peakElement(a,n);
    int index = peakElementOptimal(a,n);
    cout << index;
}