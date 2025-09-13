#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int fRecursive(int ind, vector<int> & heights, int k) {
        if(ind==0) return 0;
        int minSteps = INT_MAX;
        for(int j = 1;j<=k;j++){
            if(ind-j>=0){
                int jump = fRecursive(ind-j,heights,k) + abs(heights[ind] - heights[ind-j]);
                minSteps = min(minSteps,jump);
            } 
        }
        return minSteps;
    }

    //recursive solution
    //TC O(k^N)
    //SC O(N)
    int frogJumpRecursive(int n, vector<int> & heights, int k){
        return fRecursive(n-1,heights,k);
    }

    int fMemo(int ind, vector<int> & heights, vector<int> & dp, int k) {
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int minSteps = INT_MAX;
        for(int j = 1;j<=k;j++){
            if(ind-j>=0){
                int jump = fRecursive(ind-j,heights,k) + abs(heights[ind] - heights[ind-j]);
                minSteps = min(minSteps,jump);
            } 
            dp[ind] = minSteps;
        }
        return dp[ind];
    }

    //memoization solution
    //TC O(N*K)
    //TC O(2N)
    int frogJumpMemoization(int n, vector<int> & heights, int k){
        vector<int> dp(n,-1);
        return fMemo(n-1,heights,dp,k);
    }

    //tabulation solution
    //TC O(N*K)
    //TC O(N)
    int frogJumpTabulation(int n, vector<int> & heights, int k){
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int ind = 1;ind<n;ind++){
            int minSteps = INT_MAX;
            for(int j = 1;j<=k;j++){
                if(ind-j>=0){
                    int jump = fRecursive(ind-j,heights,k) + abs(heights[ind] - heights[ind-j]);
                    minSteps = min(minSteps,jump);
                } 
                dp[ind] = minSteps;
            }
        }
        return dp[n-1];
    }

    //space optimization solution - no need as worst case has k = n then tc will be O(N)
};

int main(){
    vector<int> heights;
    heights = {30,10,60,10,60,50};
    int n = heights.size();
    Solution s;
    //int ans = s.frogJumpRecursive(n, heights, 2);
    //int ans = s.frogJumpMemoization(n, heights, 2);
    int ans = s.frogJumpTabulation(n, heights, 2);
    cout << ans;
}