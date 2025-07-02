#include<iostream>
#include<vector>
#include<map>
using namespace std;

//brute force
//O(n^2) TC
int singleNumber(vector<int>& a, int n) {
    for(int i = 0;i<n;i++){
        int key = a[i];
        int count = 0;
        for(int j = 0; j<n;j++){
            if(a[j]==key){
                count++;
            }
        }
        if(count == 1) return key;
    }
    return -1;
}

//better1
//O(n) TC
//O(maxi) SC
//doesn't work for negative, 10^9,10^12 elements etc..
int singleNumBetter1(vector<int>& a, int n){
    int maxi = 0;
    for(int i = 0; i<n;i++){
        maxi = max(a[i],maxi);
    }
    vector<int> hash(maxi+1,0);
    for(int i = 0;i<n;i++){
        hash[a[i]]++;
    }
    for(int i = 0;i<n;i++){
        if(hash[a[i]]==1) return a[i];
    }
    return -1;
}

//better2
//O(n/2 + 1 + nlogn) TC
//O(n/2 + 1) SC
int singleNumBetter2(vector<int>& a, int n){
    map<int,int> mpp;
    for(int i = 0;i<n;i++){
        mpp[a[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1) return it.first;
    }
    return -1;
}

//optimal 
//O(n) TC
//O(1) SC
int singleNumOptimal(vector<int>& a, int n){
    int xor1 = 0;
    for(int i = 0;i<n;i++){
        xor1 = xor1 ^ a[i];
    }
    return xor1;
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
    //int m = singleNumber(a,n);
    //int m = singleNumBetter1(a,n);
    //int m = singleNumBetter2(a,n);
    int m = singleNumOptimal(a,n);
    cout << m;
}