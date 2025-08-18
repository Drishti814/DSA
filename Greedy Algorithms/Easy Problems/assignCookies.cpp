#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//TC O(NlogN+MlogM+M)   N = greed.size(),M = cookies.size();
//SC O(1)
int assignCookies(vector<int> &greed, vector<int> &cookies){
    sort(greed.begin(),greed.end());
    sort(cookies.begin(),cookies.end());
    int l = 0;
    int r = 0;
    while(r<cookies.size()){
        if(greed[l]<=cookies[r]){
            l++;
        }
        r++;
    }
    return l;
}

int main(){
    vector<int> greed = {1,5,3,3,4};
    vector<int> cookies = {4,2,1,2,1,3};
    int ans = assignCookies(greed,cookies);
    cout << ans;
}