#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//O(n)
int singleElement(vector<int> &a,int n){
    for(int i = 0;i<n;i++){
        if(i==0){
            if(a[i]!=a[i+1]) return a[i];
        }
        else if (i==n-1){
            if(a[i]!=a[i-1]) return a[i];
        }
        else{
            if(a[i]!=a[i+1] && a[i]!=a[i-1]) return a[i];
        }
    }
    return -1;
}

//optimal
//O(logn)
int singleElementOptimal(vector<int> &a,int n){
    if(n==1) return a[0];
    if(a[0]!=a[1]) return a[0];
    if(a[n-1]!=a[n-2]) return a[n-1];
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = (low + high)/2;
        if(a[mid] != a[mid-1] && a[mid] != a[mid+1]){
            return a[mid];
        }
        if((mid%2==1 && a[mid-1]==a[mid])||(mid%2==0 && a[mid]==a[mid+1])){
            low = mid+1;
        }
        else if((mid%2==1 && a[mid+1]==a[mid])||mid%2==0 && a[mid]==a[mid-1]){
            high = mid-1;
        }
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
    //int ans = singleElement(a,n);
    int ans = singleElementOptimal(a,n);
    cout << ans;
}