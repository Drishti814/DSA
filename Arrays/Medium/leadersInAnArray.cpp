#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//O(n^2) TC
//O(n) SC
vector<int> leadersArray(vector<int> &a,int n){
    vector<int> ans;
    for(int i = 0;i<n;i++){
        int leader = true;
        for(int j = i+1;j<n;j++){
            if(a[j]>a[i]){
                leader = false;
                break;
            }
        }
        if(leader == true) ans.push_back(a[i]);
    }
    return ans;
}

//optimal
//O(n) TC
//O(n) SC
vector<int> leadersArrayOptimal(vector<int> &a,int n){
    vector<int> ans;
    int leader = INT_MIN;
    for(int i = n-1;i>=0;i--){
        if(a[i]>leader){
            ans.push_back(a[i]);
        }
        leader = max(leader,a[i]);
    }
    return ans;
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
    //vector<int> m = leadersArray(a,n);
    vector<int> m = leadersArrayOptimal(a,n);
    for(auto it : m){
        cout << it << " ";
    }
}