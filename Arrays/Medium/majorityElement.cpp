#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//brute force
//TC O(n^2)
int majorityElement(vector<int> & a, int n){
    for(int i = 0;i<n;i++){
        int num = a[i];
        int count = 0;
        for(int j = 0;j<n;j++){
            if(a[i]==a[j]) count++;
        }
        if(count > n/2) return a[i];
    }
    return -1;
}

//better using hashing
//TC O(nlogn+n) if map, O(n) if unordered map,O(n^2) if worst case unordered map
//SC O(n)
int majorityElementBetter(vector<int> & a, int n){
    unordered_map<int,int> mpp;
    for(int i = 0;i<n;i++){
        mpp[a[i]]++;
    }
    for(auto it: mpp){
        if(it.second>n/2) return it.first;
    }
    return -1;
}

//optimal using Moore's voting algorithm
//O(n) TC
//O(1) SC
int majorityElementOptimal(vector<int> & a, int n){
    int count = 0;
    int element;
    for(int i = 0;i<n;i++){
        if(count==0){
            count++;
            element = a[i];
        }
        else if(a[i]==element){
            count++;
        }
        else{
            count--;
        }
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(a[i]==element) cnt++;
    }
    if(cnt > n/2) return element;
    return -1;
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
    //int m = majorityElement(a,n);
    //int m = majorityElementBetter(a,n);
    int m = majorityElementOptimal(a,n);
    cout << m;
}