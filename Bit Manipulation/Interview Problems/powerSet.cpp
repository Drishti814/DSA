#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

//TC O(n*2^n)
//SC ~ O(n*2^n) (near about not exactly)
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    int subsetCnt = 1<<n;
    for(int num = 0;num<subsetCnt;num++){
        vector<int> subset;
        for(int i = 0;i<n;i++){
            if(num&(1<<i)) subset.push_back(nums[i]);
        }
        ans.push_back(subset);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<vector<int>> ans = subsets(nums);
    for(auto it: ans){
        for(auto el : it){
            cout << el << " ";
        }
        cout << endl;
    }
}