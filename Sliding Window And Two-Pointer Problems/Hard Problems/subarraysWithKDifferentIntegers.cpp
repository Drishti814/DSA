#include<iostream>
#include<vector>
#include<map>
using namespace std;

//max consecutive ones with k zero bits that can be shifted to one

//brute force
//TC O(N^2)
//SC O(N)
int subarraysWithDiffInt(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0;i<n;i++){
        map<int,int> mpp;
        for(int j = i;j<n;j++){
            mpp[arr[j]]++;
            if(mpp.size()==k) cnt++;
            else if(mpp.size()>k) break;
        }
    }
    return cnt;
}

//optimal
//TC O(2N)
//SC O(N)
int subarraysWithDiffIntFunc(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    int l = 0;
    int r = 0;
    int zero = 0;
    map<int,int> mpp;
    while(r<n){
        mpp[arr[r]]++;
        while(mpp.size()>k){
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0) mpp.erase(arr[l]);
            l++;
        }
        cnt = cnt + (r-l+1);
        r++;
    }
    return cnt;
} 

int subarraysWithDiffIntOptimal(vector<int> &arr, int k){
    return subarraysWithDiffIntFunc(arr,k) - subarraysWithDiffIntFunc(arr,k-1);
} 

int main(){
    vector<int> arr = {1,2,1,3,4};
    //int ans = subarraysWithDiffInt(arr,3);
    int ans = subarraysWithDiffIntOptimal(arr,3);
    
    cout << ans;
}