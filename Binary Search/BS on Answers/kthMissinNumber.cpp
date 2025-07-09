#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

//brute force
//TC O(n)
int missingNum(vector<int> &a, int n, int k){
    for(int i = 0;i<n;i++){
        if(a[i]<=k) k++;
        else break;
    }
    return k;
}

//optimal
//TC O(logn)
int missingNumOptimal(vector<int> &a, int n, int k){
    int low = 0;
    int high = n-1;
    int missing = -1;
    while(low<=high){
        int mid = (low+high)/2;
         missing = a[mid]-(mid+1);
        if(missing<k) low = mid +1;
        else high = mid - 1;
    }
    return high + k + 1;    //low + k
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
    //int num = missingNum(a,n,k);
    int num = missingNumOptimal(a,n,k);
    cout << num;
}