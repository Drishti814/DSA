#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

//brute force 
//TC O(n^3)
int maxSubarraySum(vector<int> & a, int n){
    int maxLen = 0;
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += a[j];
            if(sum==0){
            maxLen = max(maxLen,j-i+1);
            }
        }
    }    
    return maxLen;
}

//optimal 
//O(n)
int maxSubarraySumOptimal(vector<int> & a, int n){
    int maxLen = 0;
    unordered_map<int,int> mpp;
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += a[i];
        if(sum==0){
            maxLen = i+1;
        }
        else{
            if(mpp.find(sum)!=mpp.end()){
                maxLen = max(maxLen,i-mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
    }  
    return maxLen;
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
    int m = maxSubarraySum(a,n);
    //int m = maxSubarraySumOptimal(a,n);
    cout << m;
}