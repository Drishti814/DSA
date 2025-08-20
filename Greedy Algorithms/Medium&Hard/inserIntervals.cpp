#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

//TC O(N)
//SC O(N)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    vector<vector<int>> results;
    int i = 0;
    while(i < intervals.size() && intervals[i][1] < newInterval[0]){
        results.push_back(intervals[i]);
        i++;
    }
    while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(intervals[i][0],newInterval[0]);
        newInterval[1] = max(intervals[i][1],newInterval[1]);
        i++;
    }
    results.push_back(newInterval);
    while(i < intervals.size()){
        results.push_back(intervals[i]); 
        i++;
    }
    return results;
}

int main(){
    int n = 6;
    vector<vector<int>> intervals = {{1, 2}, {3,4}, {5,7}, {8,10},{12,16}};
    vector<int> newInterval = {5,8};
    vector<vector<int>> ans = insert(intervals,newInterval);
    for(auto it: ans){
        for(auto el : it){
            cout << el << " ";
        }
        cout << endl;
    }
} 