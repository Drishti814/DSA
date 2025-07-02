#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

long long maxSubarraySumOptimal(vector<int> & a, int n){
    long long sum = 0; 
    long long maxSum = LONG_MIN;
    int start;
    int ansStart = -1,ansEnd= -1;
    for(int i = 0;i<n;i++){
        if(sum==0) start = i;
        sum += a[i];
        if(sum > maxSum){
            maxSum = sum;
            ansStart = start; 
            ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;
    return maxSum ;
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
    long long m = maxSubarraySumOptimal(a,n);
    cout << m;
}