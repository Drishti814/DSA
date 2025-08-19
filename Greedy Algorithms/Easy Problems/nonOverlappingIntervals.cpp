#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

static bool comparison(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

//TC O(nlogn + n)
//SC O(1)
int eraseOverlapIntervals(vector<vector<int>>& intervals){
    int n = intervals.size();
    sort(intervals.begin(),intervals.end(),comparison);
    int cnt = 1;
    int endInterval = intervals[0][1];
    for(int i = 1;i<n;i++){
        if(intervals[i][0]>=endInterval){
            cnt++;
            endInterval = intervals[i][1];
        }
    }
    return n - cnt;
}

int main(){
    int n = 6;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int ans = eraseOverlapIntervals(intervals);
    cout << ans;
} 