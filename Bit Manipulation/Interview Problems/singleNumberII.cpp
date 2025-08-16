#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<map>
using namespace std;

//brute force
//TC O(n*logm +m) n = nums.size(),m = map.size()
//SC O(m)
int singleNumber(vector<int> &nums){
    map<int,int> mpp;
    for(int i = 0;i <nums.size();i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}

//better
//TC O(n*32) n = nums.size()
//SC O(1)
int singleNumberBetter(vector<int> &nums){
    int n = nums.size();
    int ans = 0;
    for(int bitIndex = 0;bitIndex < 32; bitIndex++){
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]&(1<<bitIndex)) cnt++;
        }
        if(cnt%3==1) ans = ans|(1<<bitIndex);
    }
    return ans;
}

//optimal
//TC O(n*logn + n/3) n = nums.size()
//SC O(1)
//disadvantage - we are distortig the array
int singleNumberOptimal(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i = 1;i<n;i = i+3){
        if(nums[i]!=nums[i-1]) return nums[i-1];
    }
    return nums[n-1];
}

//most optimal
//TC O(n) n = nums.size()
//SC O(1)
int singleNumberMostOptimal(vector<int> &nums){
    int n = nums.size();
    int ones = 0;
    int twos = 0;
    for(int i = 0;i<n;i++){
        ones = ((ones^nums[i])&(~twos));
        twos = ((twos^nums[i])&(~ones));
    }
    return ones;
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
    //int ans = singleNumber(nums);
    //int ans = singleNumberBetter(nums);
    //int ans = singleNumberOptimal(nums);
    int ans = singleNumberMostOptimal(nums);
    cout << ans;
}