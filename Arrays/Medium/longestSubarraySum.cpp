#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

//brute force -- time limit exceeded(TLE) in leetcode
//TC O(n^3)
int maxSubarraySum(vector<int> & a, int n){
    int maxSum = INT_MIN;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int sum = 0;
            for(int k = i;k<=j;k++){
                sum += a[k];
            }
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
}

//better -- time limit exceeded(TLE)
//O(n^2)
int maxSubarraySumBetter(vector<int> & a, int n){
    int maxSum = INT_MIN;
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += a[j];
            maxSum = max(maxSum,sum);
            }
        }
    return maxSum;
}

//optimal using kadane's algorithm
//O(n)
long long maxSubarraySumOptimal(vector<int> & a, int n){
    long long sum = 0; 
    long long maxSum = LONG_MIN;
    for(int i = 0;i<n;i++){
        sum += a[i];
        if(sum > maxSum) maxSum = sum;
        if(sum < 0) sum = 0;
    }
    if(maxSum<0) maxSum = 0;
    return maxSum;
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
    //int m = maxSubarraySum(a,n);
    long long m = maxSubarraySumOptimal(a,n);
    cout << m;
}