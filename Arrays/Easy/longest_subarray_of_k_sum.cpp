#include<iostream>
#include<vector>
#include<map>
using namespace std;

//brute force
//O(n^2)
int longestSubarray(vector<int> &a, int n, int k){
    int len = 0;
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum+= a[j];
            if(sum==k){
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}

//better
//works fir both positives and negatives
//TC O(nlogn)ordered map, O(n)unordered map, O(n^2)worst case unordered map
//SC O(n)
int longestSubarrayBetter(vector<int> &a, int n, long long k){
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0;i<n;i++){
        sum += a[i];
        if(sum==k){
            maxLen = max(maxLen,i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem)!=preSumMap.end()){ //value in map
            int len = i - preSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){ //value not in map
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

//optimal 2 pointer approach
//TC O(2n)
//SC O(1)
int longestSubarrayOptimal(vector<int> &a, int n, long long k){
    int i = 0;
    long long sum = 0;
    int maxLen = 0;
    for(int j = 0;j<n;j++){
        sum += a[j];
        while(sum > k && i<=j){
            sum -= a[i];
            i++;
        }
        if(sum == k){
            maxLen = max(maxLen,j-i+1);
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
    long long k;
    cin >> k;
    //int m = longestSubarray(a,n,k);
    //int m = longestSubarrayBetter(a,n,k);
    int m = longestSubarrayOptimal(a,n,k);
    cout << m;
}