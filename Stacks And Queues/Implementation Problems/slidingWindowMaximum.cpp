#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;

//brute force
//TC O((n-k)*k)
//SC O(n-k)
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> ans;
    for(int i = 0;i<=n-k;i++){
        int maxi = nums[i];
        for(int j = i;j<=i+k-1;j++){
            maxi = max(maxi,nums[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

//optimal
//TC O(2N)
//SC O(k+(n-k))
vector<int> maxSlidingWindowOptimal(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for(int i = 0;i<n;i++){
        if(!dq.empty() && (dq.front()<=(i-k))){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    //vector<int> ans = maxSlidingWindow(nums,3);
    vector<int> ans = maxSlidingWindowOptimal(nums,3);
    for(auto it : ans){
        cout << it << " ";
    }
}