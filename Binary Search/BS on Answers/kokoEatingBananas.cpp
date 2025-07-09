#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

int findMax(vector<int> &a,int n){
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        maxi = max(maxi,a[i]);
    }
    return maxi;
}

long long totalHours(vector<int> &a,int n, int hourly){
    long long total = 0;
    for(int i = 0;i<n;i++){
        total += ceil((double)a[i]/(double)hourly);
    }
    return total;
}

//brute force
//TC O(n * max(a))
int requiredTime(vector<int> &a,int n, int h){
    int maxi = findMax(a,n);
    int reqTime = INT_MAX;
    for(int i = 1;i<= maxi;i++){
        int reqTime = totalHours(a,n,i);
        if(reqTime <= h) return i;
    }
    return reqTime;
}

//optimal
//TC O(n * log(max(a)))
int requiredTimeOptimal(vector<int> &a,int n, int h){
    int maxi = findMax(a,n);
    int low = 1;
    int high = maxi;
    int ans = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(totalHours(a,n,mid) <= h){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
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
    int h;
    cin >> h;
    //int bananas = requiredTime(a,n,h);
    int bananas = requiredTimeOptimal(a,n,h);
    cout << bananas;
}