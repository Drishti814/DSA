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
    int maxSumRecursive(vector<int> & a){
        int n = a.size();
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
    int maxSumMemoization(vector<int> & a){
        int n = a.size();
        vector<int> dp(n,-1);
        return fMemo(n-1,a,dp);
    }

    //tabulation solution
    //TC O(N)
    //TC O(N)
    int maxSumTabulation(vector<int> & a){
        int n = a.size();
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
    int maxSumSpaceOpt(vector<int> & a){
        int n = a.size();
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

    int rob(vector<int> & a){
        int n = a.size();
        vector<int> temp1,temp2;
        for(int i = 0;i<n;i++){
            if(i!=0) temp1.push_back(a[i]);
            if(i!=n-1) temp2.push_back(a[i]);
        }
        return max(maxSumSpaceOpt(temp1),maxSumSpaceOpt(temp2));
    }
};

int main(){
    vector<int> a;
    a = {2,7,9,3,1};
    Solution s;
    int ans = s.rob(a);
    cout << ans;
}