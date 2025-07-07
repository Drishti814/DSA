#include<iostream>
#include<vector>
using namespace std;

//brute force
//O(n^2) TC
//O(1) SC
int missingNumber(vector<int>& a) {
    for(int i = 0; i<= a.size();i++){
        int flag = 0;
        for(int j = 0;j<a.size();j++){
            if(a[j]==i){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    } 
    return -1;
}

//better
//O(2n) TC
//O(n) SC
int missingNumBetter(vector<int> &a, int n){
    vector<int> hash(n+1,0);
    for(int i = 0;i<n;i++){
        hash[a[i]] = 1;
    }
    for(int i = 0;i<n+1;i++){
        if(hash[i] == 0) return i;
    }
    return -1;
}

//optimal 1
//O(n) TC
//O(1) SC
int missingNumOptimal1(vector<int> &a, int n){
    int sumExpected = (n*(n+1))/2;
    int sumActual = 0;
    for(int i = 0; i<n;i++){
        sumActual += a[i]; 
    }
    return sumExpected - sumActual;
}

//optimal 2
//O(n) TC
//O(1) SC
int missingNumOptimal2(vector<int> &a, int n){
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i<n;i++){
        xor2 = xor2^a[i];
        xor1 = xor1^i;
    }
    xor1 = xor1^n;
    return xor1 ^ xor2;
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
    //int m = missingNumber(a);
    //int m = missingNumBetter(a,n);
    //int m = missingNumOptimal1(a,n);
    int m = missingNumOptimal2(a,n);
    cout << m;
}