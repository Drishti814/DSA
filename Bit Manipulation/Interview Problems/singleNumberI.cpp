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

//optimal
//TC O(n) n = nums.size()
//SC O(1)
int singleNumberOptimal(vector<int> &nums){
    int Xor = 0;
    for(int i = 0;i <nums.size();i++){
        Xor = Xor^nums[i];
    }
    
    return Xor;
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
    int ans = singleNumberOptimal(nums);
    cout << ans;
}