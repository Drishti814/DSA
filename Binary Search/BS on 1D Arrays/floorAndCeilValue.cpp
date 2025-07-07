#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//opposite of lower bound
int floorValue(vector<int> &a, int n, int target){
    int ans = n;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] <= target){
            ans = mid;
            low = mid+1;
        } 
        else high = mid - 1;
    }
    return a[ans];
}

//lower bound
int ceilValue(vector<int> &a, int n, int target){
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
    return a[ans];
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
    int f = floorValue(a,n,target);
    cout << f << " ";
    int c = ceilValue(a,n,target);
    cout << c;
}