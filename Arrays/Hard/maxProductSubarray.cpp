#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

//brute force 
//TC O(n^3)
//SC O(1)
int maxSubarrayProduct(vector<int> & a, int n){
    int maxProd = INT_MIN;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int prod = 1;
            for(int k = i;k<=j;k++){
                prod *= a[k];
            }
            maxProd = max(maxProd,prod);
        }
    }
    return maxProd;
}

//better
//TC O(n^2)
//SC O(1)
long long maxSubarrayProductBetter(vector<int> & a, int n){
    int maxProd = INT_MIN;
    for(int i = 0;i<n;i++){
        int prod = 1;
        for(int j = i;j<n;j++){
            prod *= a[j];
            maxProd = max(maxProd,prod);
            }
        }
    return maxProd;
}

//optimal
//TC O(n)
//SC O(1)
long long maxSubarrayProductOptimal(vector<int> & a, int n){
    long long prefix = 1; 
    long long suffix = 1; 
    long long maxProd = LONG_MIN;
    for(int i = 0;i<n;i++){
        if(prefix==0) prefix = 1;
        if(suffix==0) suffix = 1;
        prefix *= a[i];
        suffix *= a[n-i-1];
        maxProd = max(maxProd,max(prefix,suffix));
    }
    return maxProd;
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
    //long long m = maxSubarrayProduct(a,n);
    //long long m = maxSubarrayProductBetter(a,n);
    long long m = maxSubarrayProductOptimal(a,n);
    cout << m;
}