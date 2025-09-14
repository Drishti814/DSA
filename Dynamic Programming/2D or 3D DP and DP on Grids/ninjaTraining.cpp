#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int fRecursive(int day, vector<vector<int>> & points, int last) {
        if(day==0){
            int maxx = INT_MIN;
            for(int i = 0;i<3;i++){
                if(i!=last) maxx = max(points[0][i],maxx);
            }
            return maxx;
        }
        int maxi = 0;
        for(int i = 0;i<3;i++){
            if(i!=last){
                int point = points[day][i] + fRecursive(day-1,points,i);
                maxi = max(maxi,point);
            } 
        }
        return maxi;
    }

    //recursive solution
    //TC O(3^N)
    //SC O(N)
    int ninjaTrainingRecursive(int n, vector<vector<int>> & points){
        return fRecursive(n-1,points,3);    //3 implies no task is performed
    }

    int fMemo(int day, vector<vector<int>> & points, int last, vector<vector<int>> & dp) {
        if(day==0){
        int maxx = INT_MIN;
        for(int i = 0;i<3;i++){
            if(i!=last) maxx = max(points[0][i],maxx);
        }
        return maxx;
        }
        if(dp[day][last]!=-1) return dp[day][last];
        int maxi = 0;
        for(int i = 0;i<3;i++){
            if(i!=last){
                int point = points[day][i] + fMemo(day-1,points,i,dp);
                maxi = max(maxi,point);
            } 
        }
        return dp[day][last] = maxi;
    }

    //memoization solution
    //TC O(12N)
    //TC O(5N)
    int ninjaTrainingMemoization(int n, vector<vector<int>> & points){
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return fMemo(n-1,points,3,dp);
    }

    //tabulation solution
    //TC O(12N)
    //TC O(4N)
    int ninjaTrainingTabulation(int n, vector<vector<int>> & points){
        vector<vector<int>> dp(n,vector<int> (4,-1));
        dp[0][0] = max(points[0][1],points[0][2]);
        dp[0][1] = max(points[0][0],points[0][2]);
        dp[0][2] = max(points[0][0],points[0][1]);
        dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
        for(int day = 1;day<n;day++){
            for(int last = 0;last<4;last++){
                dp[day][last] = 0;
                int maxi = 0;
                for(int i = 0;i<3;i++){
                    if(i!=last){
                        int point = points[day][i] + dp[day-1][i];
                        maxi = max(maxi,point);
                    } 
                }
                dp[day][last] = maxi;
            }
        }
        return dp[n-1][3];
    }

    //space optimization solution
    //TC O(12N)
    //TC O(8)
    int ninjaTrainingSpaceOpt(int n, vector<vector<int>> & points){
        vector<int> prev(4,-1);
        prev[0] = max(points[0][1],points[0][2]);
        prev[1] = max(points[0][0],points[0][2]);
        prev[2] = max(points[0][0],points[0][1]);
        prev[3] = max(points[0][0],max(points[0][1],points[0][2]));
        for(int day = 1;day<n;day++){
            vector<int> curr(4,-1);
            for(int last = 0;last<4;last++){
                curr[last] = 0;
                int maxi = 0;
                for(int i = 0;i<3;i++){
                    if(i!=last){
                        int point = points[day][i] + prev[i];
                        maxi = max(maxi,point);
                    } 
                    curr[last] = maxi;
                }
            }
            prev = curr;
        }
        return prev[3];
    }
};

int main(){
     vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};
    int n = points.size();
    Solution s;
    //int ans = s.ninjaTrainingRecursive(n, points);
    //int ans = s.ninjaTrainingMemoization(n, points);
    int ans = s.ninjaTrainingTabulation(n, points);
    //int ans = s.ninjaTrainingSpaceOpt(n, points);
    cout << ans;
}