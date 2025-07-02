#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//O(1.5n) TC
//O(n) SC
vector<int> rearrangeArray(vector<int> &a,int n){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0;i<n;i++){
        if(a[i]>0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    for(int i = 0;i<n/2;i++){
        a[2*i]= pos[i];
        a[2*i+1]= neg[i];
    }
    return a;
}

//optimal
//O(n) TC
//O(n) SC
vector<int> rearrangeArrayOptimal(vector<int> &a,int n){
    vector<int> ans(n);
    int pos = 0;
    int neg = 1;
    for(int i = 0;i<n;i++){
        if(a[i]>0){
            ans[pos] = a[i];
            pos+=2;
        }
        else{
            ans[neg] = a[i];
            neg+=2;
        }
    }
    return ans;
}

//when positive != negative
//O(2n) TC
//O(n) SC
vector<int> alternateArray(vector<int> &a,int n){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0;i<n;i++){
        if(a[i]>0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    if(pos.size()>neg.size()){
        for(int i = 0;i<neg.size();i++){
            a[2*i]= pos[i];
            a[2*i+1]= neg[i];
        }
        for(int i = neg.size();i<pos.size();i++){
            a[i] = pos[i];
        }
    }
    if(neg.size()>pos.size()){
        for(int i = 0;i<pos.size();i++){
            a[2*i]= pos[i];
            a[2*i+1]= neg[i];
        }
        for(int i = pos.size();i<neg.size();i++){
            a[i] = neg[i];
        }
    }
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
    //vector<int> m = rearrangeArray(a,n);
    //vector<int> m = rearrangeArrayOptimal(a,n);
    vector<int> m = alternateArray(a,n);
    for(auto it: m){
        cout << it << " ";
    }
}