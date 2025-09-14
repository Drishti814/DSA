#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int fRecursive(int i, int j) {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        int up = fRecursive(i-1,j);
        int left = fRecursive(i,j-1);
        return up + left;
    }

    //recursive solution
    //TC O(2^(M*N))
    //SC O((M-1)+(N-1))
    int uniquePathsRecursive(int m, int n){
        return fRecursive(m-1,n-1);    
    }

    int fMemo(int i, int j, vector<vector<int>> & dp) {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = fMemo(i-1,j,dp);
        int left = fMemo(i,j-1,dp);
        return dp[i][j] = up + left;
    }

    //memoization solution
    //TC O(M*N)
    //SC O((M-1)+(N-1)+(M*N))
    int uniquePathsMemoization(int m, int n){
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return fMemo(m-1,n-1,dp);    
    }

    //tabulation solution
    //TC O(M*N)
    //SC O(M*N)
    int uniquePathsTabulation(int m, int n){
        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[0][0] = 1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0 && j==0) dp[0][0] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }

    //space optimization solution
    //TC O(M*N)
    //TC O(N)
    int uniquePathsSpaceOpt(int m, int n){
        vector<int> prev(n,0);
        for(int i = 0;i<m;i++){
            vector<int> curr(n,0);
            for(int j = 0;j<n;j++){
                if(i==0 && j==0) curr[j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

int main(){
    int m,n;
    cin >> m >> n;
    Solution s;
    //int ans = s.uniquePathsRecursive(m,n);
    //int ans = s.uniquePathsMemoization(m,n);
    //int ans = s.uniquePathsTabulation(m,n);
    int ans = s.uniquePathsSpaceOpt(m,n);
    cout << ans;
}