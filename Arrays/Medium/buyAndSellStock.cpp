#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

int buyAndSell(vector<int> &a,int n){
    int buy = a[0];
    int maxProfit = 0;
    for(int i = 0;i<n;i++){
        int profit = a[i] - buy;
        maxProfit = max(maxProfit,profit);
        buy = min(buy,a[i]);
    }
    return maxProfit;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    long long m = buyAndSell(a,n);
    cout << m;
}