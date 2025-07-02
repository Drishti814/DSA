#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//brute force
//O(n^2)
int twoSumProblem(vector<int> &a, int n, int target){
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(i==j) continue;
            if(a[i]+a[j]==target){
                cout << i <<" " << j << endl;
                return true;
            }
        }
    }
    return false;
}

//better
//O(nlogn) TC map
//O(n) TC unordered map, O(n^2) worst case
//O(n) SC
int twoSumBetter(vector<int> &a, int n, int target){
    map<int,int> hashMap;
    for(int i = 0;i<n;i++){
        if(hashMap.find(target-a[i])!=hashMap.end()){
            return true;
        }
        hashMap[a[i]] = i;
    }
    return false;
}

//optimal
//O(n)+O(nlogn) TC
//O(1) SC
int twoSumOptimal(vector<int> &a, int n, int target){
    sort(a.begin(),a.end());
    int left = 0;
    int right = n-1;
    while(left<right){
        if(a[left]+a[right]==target){
            return true;
        }
        else if(a[left]+a[right]<target){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
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
    int target;
    cin >> target;
    //int m = twoSumProblem(a,n, target);
    //int m = twoSumBetter(a,n, target);
    int m = twoSumOptimal(a,n, target);
    cout << m;
}