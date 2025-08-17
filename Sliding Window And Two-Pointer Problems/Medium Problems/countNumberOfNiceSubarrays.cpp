#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//TC O(2n)
//SC O(1)
int niceSubarrays(vector<int> &a, int n, long long k){
    if(k<0) return 0;
    int l = 0;
    int r = 0;
    long long sum = 0;
    int cnt = 0;
    while(r < n){
        sum = sum + (a[r]%2);
        while(sum > k){
            sum -= (a[l]%2);
            l++;
        }
        cnt = cnt+(r-l+1);
        r++;
    }
    return cnt;
}

int countNiceSubarrays(vector<int> &a, int n, long long k){
    return niceSubarrays(a,n,k) - niceSubarrays(a,n,k-1);
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
    long long k;
    cin >> k;
    int m = countNiceSubarrays(a,n,k);
    cout << m;
}