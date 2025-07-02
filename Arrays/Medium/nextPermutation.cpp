#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

//O(3n) TC
vector<int> nextPermutation(vector<int> &a,int n){
    int x = -1;
    for(int i = n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            x = i;
            break;
        } 
    }
    if(x==-1){
        reverse(a.begin(),a.end());
        return a;
    }
    for(int i = n-1;i>x;i--){
        if(a[i]>a[x]){
            swap(a[i],a[x]);
            break;
        }
    }
    reverse(a.begin()+x+1,a.end());
    return a;
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
    vector<int> m = nextPermutation(a,n);
    for(auto it : m){
        cout << it << " ";
    }
}