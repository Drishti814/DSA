#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

int findMax(vector<int> &weight,int n){
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        maxi = max(weight[i],maxi);
    }
    return maxi;
}

int summ(vector<int> &weight,int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum+=weight[i];
    }
    return sum;
}

int daysRequired(vector<int> &weight, int n, int capacity){
    int day = 1;
    int load = 0;
    for(int i = 0;i<n;i++){
        if(load + weight[i]>capacity){
            day = day+1;
            load = weight[i];
        }
        else load += weight[i];
    }
    return day;
}

//brute force
//TC O(n*(sum-max+1))
int leastCapacity(vector<int> &weight, int n, int d){
    int maxi = findMax(weight,n);
    int sum = summ(weight,n);
    for(int i = maxi;i<=sum;i++){
        int daysReq = daysRequired(weight,n,i);
        if(daysReq<=d) return i;
    }
    return -1;
}

//optimal
//TC O(n*log(sum-max+1))
int leastCapacityOptimal(vector<int> &weight, int n, int d){
    int maxi = findMax(weight,n);
    int sum = summ(weight,n);
    int ans = -1;
    int low = maxi;
    int high = sum;
    while(low<=high){
        int mid = (low+high)/2;
        if(daysRequired(weight,n,mid)<=d){
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
    vector<int> weight;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        weight.push_back(x);
    }
    int d;
    cin >> d;
    //int ans = leastCapacity(weight,n,d);
    int ans = leastCapacityOptimal(weight,n,d);
    cout << ans;
}