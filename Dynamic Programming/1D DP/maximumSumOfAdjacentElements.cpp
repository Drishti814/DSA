#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int fRecursive(int ind, vector<int> & a) {
        if(ind==0) return a[0];
        if(ind<0) return 0;
        int pick = a[ind] + fRecursive(ind-2,a);
        int notpick = 0 + fRecursive(ind-1,a);
        return max(pick,notpick);
    }

    //recursive solution
    //TC O(2^N)
    //SC O(N)
    int maxSumRecursive(int n, vector<int> & a){
        return fRecursive(n-1,a);
    }

    int fMemo(int ind, vector<int> & a, vector<int> & dp) {
        if(ind==0) return a[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = a[ind] + fMemo(ind-2,a,dp);
        int notpick = 0 + fMemo(ind-1,a,dp);
        dp[ind] = max(pick,notpick);
        return dp[ind];
    }

    //memoization solution
    //TC O(N)
    //TC O(2N)
    int maxSumMemoization(int n, vector<int> & a){
        vector<int> dp(n,-1);
        return fMemo(n-1,a,dp);
    }

    //tabulation solution
    //TC O(N)
    //TC O(N)
    int maxSumTabulation(int n, vector<int> & a){
        vector<int> dp(n,-1);
        dp[0] = a[0];
        for(int ind = 1;ind<n;ind++){
            int pick = a[ind];
            if(ind>1) pick +=  dp[ind-2];
            int notpick = 0 ;
            if(ind>0) notpick +=  dp[ind-1];
            dp[ind] = max(pick,notpick);
        }
        return dp[n-1];
    }

    //space optimization solution
    //TC O(N)
    //TC O(1)
    int maxSumSpaceOpt(int n, vector<int> & a){
        int prev = a[0];
        int prev2 = 0;
        for(int ind = 1;ind<n;ind++){
            int pick = a[ind];
            if(ind>1) pick +=  prev2;
            int notpick = 0 ;
            if(ind>0) notpick +=  prev;
            int curr = max(pick,notpick); 
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main(){
    vector<int> a;
    a = {2,7,9,3,1};
    int n = a.size();
    Solution s;
    //int ans = s.maxSumRecursive(n, a);
    //int ans = s.maxSumMemoization(n, a);
    //int ans = s.maxSumTabulation(n, a);
    int ans = s.maxSumSpaceOpt(n, a);
    cout << ans;
}