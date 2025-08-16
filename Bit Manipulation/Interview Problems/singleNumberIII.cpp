#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<map>
using namespace std;

//brute force
//TC O(n*logm +m) n = nums.size(),m = map.size()
//SC O(m) m = n/2 +1
vector<int> singleNumber(vector<int> &nums){
    vector<int> ans;
    map<int,int> mpp;
    for(int i = 0;i <nums.size();i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1){
             ans.push_back(it.first);
        }
    }
    return ans;
}

//optimal
//TC O(2n) n = nums.size()
//SC O(1)
vector<int> singleNumberOptimal(vector<int> &nums){
    int n = nums.size();
    int xorr = 0;
    for(int i = 0;i<n;i++){
        xorr = xorr^nums[i];
    }
    long rightmost = (xorr & (xorr-1))^xorr;
    int b1 = 0;
    int b2 = 0;
    for(int i = 0;i<n;i++){
        if(nums[i]&rightmost) b1 = b1^nums[i];
        else b2 = b2^nums[i];
    }
    return {b1,b2};
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
    //vector<int> ans = singleNumber(nums);
    vector<int> ans = singleNumberOptimal(nums);
    for(auto it : ans){
        cout << it << " ";
    }
}