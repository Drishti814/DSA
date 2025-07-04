#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;

//brute force
//TC O(n^2)
//SC O(1) as ls will always have 2 elements
vector<int> majorityElement(vector<int> & a, int n){
    vector<int> ls;
    for(int i = 0;i<n;i++){
        if(ls.size()==0||ls[0]!=a[i]){
            int el = a[i];
            int count = 0;
            for(int j = 0;j<n;j++){
                if(a[j]==el){
                    count++;
                }
            }
            if(count > (n/3)){
                ls.push_back(el);
            }
            if(ls.size()==2) break;
        }
    }
    return ls;
}

//better using hashing
//TC O(nlogn+n) if map, O(n) if unordered map,O(n^2) if worst case unordered map
//SC O(n)
vector<int> majorityElementBetter(vector<int> & a, int n){
    vector<int> ls;
    unordered_map<int,int> mpp;
    for(int i = 0;i<n;i++){
        mpp[a[i]]++;
    }
    for(auto it: mpp){
        if(it.second>n/3){
            ls.push_back(it.first);
        }
        if(ls.size()==2) break;
    }
    return ls;
}

//optimal 
//TC O(n)
//SC O(1) as ls will always have 2 elements
vector<int> majorityElementOptimal(vector<int> & a, int n){
    vector<int> ls;
    int count1 = 0;
    int count2 = 0;
    int el1 = INT_MIN,el2 = INT_MIN;
    for(int i = 0;i<n;i++){
        if(count1==0 && a[i]!=el2){
            el1 = a[i];
            count1++;
        }
        else if(count2==0 && a[i]!=el1){
            el2 = a[i];
            count2++;
        }
        else if(a[i]==el1){
            count1++;
        }
        else if(a[i]==el2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0;i<n;i++){
        if(a[i]==el1) cnt1++;
        if(a[i]==el2) cnt2++;
    }
    if(cnt1 > n/3) ls.push_back(el1);
    if(cnt2 > n/3) ls.push_back(el2);
    return ls;
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
    //vector<int> m = majorityElement(a,n);
    //vector<int> m = majorityElementBetter(a,n);
    vector<int> m = majorityElementOptimal(a,n);
    for(auto it : m){
        cout << it << " ";
    }
}