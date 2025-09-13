#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int fRecursive(int ind, vector<int> & heights) {
        if(ind==0) return 0;
        int oneStep = fRecursive(ind-1,heights) + abs(heights[ind] - heights[ind-1]);
        int twoStep = INT_MAX;
        if(ind>1){
            twoStep = fRecursive(ind-2,heights) + abs(heights[ind] - heights[ind-2]);
        } 
        return min(oneStep,twoStep);
    }

    //recursive solution
    //TC O(2^N)
    //SC O(N)
    int frogJumpRecursive(int n, vector<int> & heights){
        return fRecursive(n-1,heights);
    }

    int fMemo(int ind, vector<int> & heights, vector<int> & dp) {
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int oneStep = fMemo(ind-1,heights,dp) + abs(heights[ind] - heights[ind-1]);
        int twoStep = INT_MAX;
        if(ind>1){
            twoStep = fMemo(ind-2,heights,dp) + abs(heights[ind] - heights[ind-2]);
        } 
        return min(oneStep,twoStep);
    }

    //memoization solution
    //TC O(N)
    //TC O(2N)
    int frogJumpMemoization(int n, vector<int> & heights){
        vector<int> dp(n,-1);
        return fMemo(n-1,heights,dp);
    }

    //tabulation solution
    //TC O(N)
    //TC O(N)
    int frogJumpTabulation(int n, vector<int> & heights){
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int ind = 1;ind<n;ind++){
            int oneStep = dp[ind-1] + abs(heights[ind] - heights[ind-1]);
            int twoStep = INT_MAX;
            if(ind>1){
                twoStep = dp[ind-2] + abs(heights[ind] - heights[ind-2]);
            } 
            dp[ind] = min(oneStep,twoStep);
        }
        return dp[n-1];
    }

    //space optimization solution
    //TC O(N)
    //TC O(1)
    int frogJumpSpaceOpt(int n, vector<int> & heights){
        int prev = 0;
        int prev2 = 0;
        for(int ind = 1;ind<n;ind++){
            int oneStep = prev + abs(heights[ind] - heights[ind-1]);
            int twoStep = INT_MAX;
            if(ind>1){
                twoStep = prev2 + abs(heights[ind] - heights[ind-2]);
            } 
            int curr = min(oneStep,twoStep);
            prev2 = prev;
            prev = curr;

        }
        return prev;
    }
};

int main(){
    vector<int> heights;
    heights = {30,10,60,10,60,50};
    int n = heights.size();
    Solution s;
    //int ans = s.frogJumpRecursive(n, heights);
    //int ans = s.frogJumpMemoization(n, heights);
    //int ans = s.frogJumpTabulation(n, heights);
    int ans = s.frogJumpSpaceOpt(n, heights);
    cout << ans;
}