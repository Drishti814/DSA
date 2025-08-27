#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

//brute force
//TC O(NlogN + 2N)
//SC O(N)
vector<vector<int>> merge(vector<vector<int>>& intervals){
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> results;
    for(int i = 0;i<n;i++){
        int start = intervals[i][0];
        int end = intervals[i][1];
        if(!results.empty() && end<=results.back()[1]){
            continue;
        }
        for(int j = i+1;j<n;j++){
            if(intervals[j][0] <= end){
                end = max(end,intervals[j][1]);
            }
            else break;
        }
        results.push_back({start,end});
    }
    return results;
}

//optimal
//TC O(N)
//SC O(N)
vector<vector<int>> mergeOptimal(vector<vector<int>>& intervals){
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> results;
    for(int i = 0;i<n;i++){
        if(results.empty() || intervals[i][0] > results.back()[1]){
            results.push_back(intervals[i]);
        }
        else{
            results.back()[1] = max(results.back()[1],intervals[i][1]);
        }
    }
    return results;
}

int main(){
    int n = 6;
    vector<vector<int>> intervals = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    //vector<vector<int>> ans = merge(intervals);
    vector<vector<int>> ans = mergeOptimal(intervals);
    for(auto it: ans){
        for(auto el : it){
            cout << el << " ";
        }
        cout << endl;
    }
} 