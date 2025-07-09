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

int cntStud(vector<int> &a,int n, int maxPages){
    int studNum = 1;
    int lastStud = 0;
    for(int i = 0;i<n;i++){
        if(lastStud+a[i] > maxPages){
            studNum++;
            lastStud = a[i];
        }
        else lastStud += a[i];
    }
    return studNum;
}

//brute force
//TC O(n*(sum-max+1))
int minOfMaxPages(vector<int> &a, int n, int k){
    if(k>n) return -1;
    int maxi = findMax(a,n);
    int sum = summ(a,n);
    for(int i = maxi;i<=sum;i++){
        if(cntStud(a,n,i)==k) return i;
    }
    return maxi;
}

//Optimal
//TC O(n*log(sum-max+1))
int minOfMaxPagesOptimal(vector<int> &a, int n, int k){
    if(k>n) return -1;
    int low = findMax(a,n);
    int high = summ(a,n);
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(cntStud(a,n,mid)<=k){
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
    //int ans = minOfMaxPages(a,n,k);
    int ans = minOfMaxPagesOptimal(a,n,k);
    cout << ans;
}