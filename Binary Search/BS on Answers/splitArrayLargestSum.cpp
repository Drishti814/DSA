#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

int findMax(vector<int> &a,int n){
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        maxi = max(a[i],maxi);
    }
    return maxi;
}

int summ(vector<int> &a,int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

int cntSplit(vector<int> &a,int n, int maxPages){
    int splitNum = 1;
    int summ = 0;
    for(int i = 0;i<n;i++){
        if(summ+a[i] > maxPages){
            splitNum++;
            summ = a[i];
        }
        else summ += a[i];
    }
    return splitNum;
}

//brute force
//TC O(n*(sum-max+1))
int splitLargestSum(vector<int> &a, int n, int k){
    if(k>n) return -1;
    int maxi = findMax(a,n);
    int sum = summ(a,n);
    for(int i = maxi;i<=sum;i++){
        if(cntSplit(a,n,i)==k) return i;
    }
    return maxi;
}

//Optimal
//TC O(n*log(sum-max+1))
int splitLargestSumOptimal(vector<int> &a, int n, int k){
    if(k>n) return -1;
    int low = findMax(a,n);
    int high = summ(a,n);
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(cntSplit(a,n,mid)<=k){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int k;
    cin >> k;
    //int ans = splitLargestSum(a,n,k);
    int ans = splitLargestSumOptimal(a,n,k);
    cout << ans;
}