#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//TC O(n1+n2)
//SC O(n1+n2)
double medianArrays(vector<int>a1, int n1, vector<int>a2, int n2 ){
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
    int n3 = a3.size();
    if(n3%2==0){
        return (double)(((double)a3[n3/2])+((double)a3[(n3/2)-1]))/2.0;
    }
    return a3[n3/2];
}

//better
//TC O(n1+n2)
//SC O(1)
double medianArraysBetter(vector<int>a1, int n1, vector<int>a2, int n2 ){
    int n3 = n1+n2;
    int low = 0;
    int high = 0;
    int cnt = 0;
    int val1 = n3/2;
    int val2 = val1 -1;
    int el1 = -1, el2 = -1;
    while(low<n1 && high<n2){
        if(a1[low]<=a2[high]){
            if(cnt==val1) el1 = a1[low];
            if(cnt==val2) el2 = a1[low];
            cnt++;
            low++;

        }
        else{
            if(cnt==val1) el1 = a2[high];
            if(cnt==val2) el2 = a2[high];
            cnt++;
            high++;
        } 
    }
    while(low<n1){
        if(cnt==val1) el1 = a1[low];
        if(cnt==val2) el2 = a1[low];
        cnt++;
        low++;
    }
    while(high<n2){
        if(cnt==val1) el1 = a2[high];
        if(cnt==val2) el2 = a2[high];
        cnt++;
        high++;
    }
    if(n3%2==0){
        return (double)((double)(el1+el2))/2.0;
    }
    return (double)el1;
}

//optimal
//TC O(min(logn1,logn2))
//SC O(1)
double medianArraysOptimal(vector<int>a1, int n1, vector<int>a2, int n2 ){
    if(n1>n2) return medianArraysOptimal(a2,n2,a1,n1);
    int n3 = n1+n2;
    int low = 0;
    int high = n1;
    int left = (n1+n2+1)/2;
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
            if(n3%2==1) return max(l1,l2);
            else return (double)((max(l1,l2)+min(r1,r2)))/2.0;
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
    //double ans = medianArrays(a1,n1,a2,n2);
    //double ans = medianArraysBetter(a1,n1,a2,n2);
    double ans = medianArraysOptimal(a1,n1,a2,n2);
    cout << ans;
}