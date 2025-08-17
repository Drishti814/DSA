#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//brute force -- time limit exceeded(TLE) in leetcode
//TC O(n^3)
//SC O(1)
int countBinarySubarray(vector<int> &a, int n, int k){
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int sum = 0;
            for(int x = i;x<=j;x++){
                sum += a[x];
            }
            if(sum==k) count++;
        }
    }
    return count;
}

//better -- time limit exceeded(TLE)
//TC O(n^2)
//SC O(1)
int countBinarySubarrayBetter(vector<int> & a, int n, int k){
    int count = 0;
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += a[j];
            if(sum==k) count++;
        }     
        }
        return count;
}

//optimal 
//TC O(nlogn) map
//TC O(n*1) if unordered map O(n*n) worst case umap
//SC O(n)
int countBinarySubarrayOptimal(vector<int> &a, int n, long long k){
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int count = 0;
    for(int i = 0;i<n;i++){
        preSum = preSum + a[i];
        int rem = preSum - k;
        count += mpp[rem];
        mpp[preSum] += 1;
    }
    return count;
}

//most optimal 
//TC O(2n)
//SC O(1)
int countBinarySubarrayMostOptimalReturn(vector<int> &a, int n, long long k){
    if(k<0) return 0;
    int l = 0;
    int r = 0;
    long long sum = 0;
    int cnt = 0;
    while(r < n){
        sum = sum + a[r];
        while(sum > k){
            sum -= a[l];
            l++;
        }
        cnt = cnt+(r-l+1);
        r++;
    }
    return cnt;
}

int countBinarySubarrayMostOptimal(vector<int> &a, int n, long long k){
    return countBinarySubarrayMostOptimalReturn(a,n,k) - countBinarySubarrayMostOptimalReturn(a,n,k-1);
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    long long k;
    cin >> k;
    //int m = countBinarySubarray(a,n,k);
    //int m = countBinarySubarrayBetter(a,n,k);
    //int m = countBinarySubarrayOptimal(a,n,k);
    int m = countBinarySubarrayMostOptimal(a,n,k);
    cout << m;
}