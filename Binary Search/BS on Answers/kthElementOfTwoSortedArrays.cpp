#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//TC O(n1+n2)
//SC O(n1+n2)
double kthElArrays(vector<int>a1, int n1, vector<int>a2, int n2, int k){
    vector<int> a3;
    int low = 0;
    int high = 0;
    while(low<n1 && high<n2){
        if(a1[low]<=a2[high]){
            a3.push_back(a1[low]);
            low++;
        }
        else{
            a3.push_back(a2[high]);
            high++;
        } 
    }
    while(low<n1){
        a3.push_back(a1[low]);
        low++;
    }
    while(high<n2){
        a3.push_back(a2[high]);
        high++;
    }
    return a3[k-1];
}

//better
//TC O(n1+n2)
//SC O(1)
double kthElArraysBetter(vector<int>a1, int n1, vector<int>a2, int n2, int k ){
    int n3 = n1+n2;
    int low = 0;
    int high = 0;
    int cnt = 0;
    int val1 = k-1;
    int el1 = -1;
    while(low<n1 && high<n2){
        if(a1[low]<=a2[high]){
            if(cnt==val1) el1 = a1[low];
            cnt++;
            low++;

        }
        else{
            if(cnt==val1) el1 = a2[high];
            cnt++;
            high++;
        } 
    }
    while(low<n1){
        if(cnt==val1) el1 = a1[low];
        cnt++;
        low++;
    }
    while(high<n2){
        if(cnt==val1) el1 = a2[high];
        cnt++;
        high++;
    }
    return el1;
}

//optimal
//TC O(min(logn1,logn2))
//SC O(1)
double kthElArraysOptimal(vector<int>a1, int n1, vector<int>a2, int n2, int k ){
    if(n1>n2) return kthElArraysOptimal(a2,n2,a1,n1,k);
    int n3 = n1+n2;
    int low = max(0,k-n2);
    int high = min(n1,k);
    int left = k;
    while(low<=high){
        int mid1 = low+high >> 1;   //low+high/2
        int mid2 = left - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        if(mid1<n1) r1 = a1[mid1];
        if(mid2<n2) r2 = a2[mid2];
        if(mid1-1>=0) l1 = a1[mid1 - 1];
        if(mid2-1>=0) l2 = a2[mid2 - 1];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main(){
    int n1, n2;
    cin >> n1;
    cin >> n2;
    vector<int> a1;
    vector<int> a2;
    for(int i =0;i<n1;i++){
        int x;
        cin >> x;
        a1.push_back(x);
    }
    for(int i =0;i<n2;i++){
        int x;
        cin >> x;
        a2.push_back(x);
    }
    int k;
    cin >> k;
    //double ans = kthElArrays(a1,n1,a2,n2,k);
    //double ans = kthElArraysBetter(a1,n1,a2,n2,k);
    double ans = kthElArraysOptimal(a1,n1,a2,n2,k);
    cout << ans;
}