#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

vector<int> findMin(vector<int> &coins,int val){
    int n = coins.size();
    vector<int> ans;
    for(int i = n-1;i>=0;i--){
        while(val>=coins[i]){
            ans.push_back(coins[i]);
            val -= coins[i];
        }
    }
    return ans;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    vector<int> ans = findMin(coins,49);
    for(auto it : ans){
        cout << it << " ";
    }
} 