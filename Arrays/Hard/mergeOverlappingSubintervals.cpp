#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//brute force
//TC O(nlogn + 2n)
//SC (n)
vector<vector<int>> mergeOverlap(vector<vector<int>> &a, int n){
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for(int i = 0;i<n;i++){
        int start = a[i][0];
        int end = a[i][1];
        if(!ans.empty() && end<=ans.back()[1]) continue;
        for(int j = i+1;j<n;j++){
            if(a[j][0]<= end){
                end = max(end,a[j][1]);
            }
            else break;
        }
        ans.push_back({start,end});
    }
    return ans;
}

//optimal
//TC O(nlogn + n) 
//SC O(n) 
vector<vector<int>> mergeOverlapOptimal(vector<vector<int>> &a, int n){
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for(int i = 0;i<n;i++){
        if(ans.empty() || a[i][0] > ans.back()[1]){
            ans.push_back(a[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],a[i][1]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n,(vector<int>(2)));
    for(int i = 0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
    }
    //vector<vector<int>> m = mergeOverlap(a,n);
    vector<vector<int>> m = mergeOverlapOptimal(a,n);
    for(auto it : m){
        cout << it[0] << " " << it[1] << endl;
    }
}