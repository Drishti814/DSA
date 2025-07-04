#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//brute force -- time limit exceeded(TLE) in leetcode
//TC O(n^3)
int countSubarray(vector<int> &a, int n, int k){
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int sum = 0;
            for(int x = i;x<=j;x++){
                sum += a[x];
                if(sum==k) count++;
            }
        }
    }
    return count;
}

//better -- time limit exceeded(TLE)
//O(n^2)
int countSubarrayBetter(vector<int> & a, int n, int k){
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
int countSubarrayOptimal(vector<int> &a, int n, long long k){
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
    int m = countSubarray(a,n,k);
    //int m = countSubarrayBetter(a,n,k);
    //int m = countSubarrayOptimal(a,n,k);
    cout << m;
}