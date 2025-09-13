#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int fRecursive(int ind) {
        if(ind==0) return 1;
        if(ind==1) return 1;
        int one = fRecursive(ind-1);
        int two = fRecursive(ind-2);
        return one+two;
    }

    //recursive solution
    //TC O(2^N)
    //SC O(N)
    int climbStairsRecursive(int n){
        return fRecursive(n);
    }

    int fMemo(int ind, vector<int> & dp) {
        if(ind==0) return 1;
        if(ind==1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int one = fMemo(ind-1,dp);
        int two = fMemo(ind-2,dp);
        dp[ind] = one + two;
        return dp[ind];
    }

    //memoization solution
    //TC O(N)
    //TC O(2N)
    int climbStairsMemoization(int n){
        vector<int> dp(n+1,-1);
        return fMemo(n,dp);
    }

    //tabulation solution
    //TC O(N)
    //TC O(N)
    int climbStairsTabulation(int n){
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int ind = 2;ind<=n;ind++){
            int one = dp[ind-1];
            int two = dp[ind-2];
            dp[ind] = one + two;
        }
        return dp[n];
    }

    //space optimization solution
    //TC O(N)
    //TC O(1)
    int climbStairsSpaceOpt(int n) {
        int prev2 = 1;
        int prev = 1;
        for(int i=2; i<=n; i++){
            int curr = prev+prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main(){
    int n;
    cin >> n;
    Solution s;
    //int ans = s.climbStairsRecursive(n);
    //int ans = s.climbStairsMemoization(n);
    int ans = s.climbStairsTabulation(n);
    //int ans = s.climbStairsSpaceOpt(n);
    cout << ans;
}