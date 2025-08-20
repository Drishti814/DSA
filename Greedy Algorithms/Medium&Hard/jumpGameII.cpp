#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int jumpHelper(vector<int>& nums, int index, int jumps){
    int n = nums.size();
    if(index>=(n-1)) return jumps;
    int mini = INT_MAX;
    for(int i = 1; i <= nums[index];i++){
        mini = min(mini,jumpHelper(nums,index+i,jumps+1));
    }
    return mini;
}

//brute force
//TC O(N^N)
//SC O(N)
int jump(vector<int>& nums){
    return jumpHelper(nums,0,0);
}

//better DP solution    (haven't studied DP yet)
//TC O(N^2)
//SC O(N^2)

//optimal
//TC O(N)
//SC O(1)
int jumpOptimal(vector<int>& nums){
    int n = nums.size();
    int jumps = 0;
    int l = 0;
    int r = 0;
    while(r<n-1){
        int farthest = 0;
        for(int i = l;i<=r;i++){
            farthest = max(i+nums[i],farthest);
        }
        l = r+1;
        r = farthest;
        jumps++;
    }
    return jumps;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    //int ans = jump(nums);
    int ans = jumpOptimal(nums);
    cout << ans;
}
