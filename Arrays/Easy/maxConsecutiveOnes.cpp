#include<iostream>
#include<vector>
using namespace std;

int maxConsecutiveOnes(vector<int> &a, int n){
    int count = 0;
    int maxi = 0;
    for(int i = 0; i<n; i++){
        if(a[i]==1){
            count++;
            maxi = max(maxi,count);
        }
        else{
            count = 0;
        }
    }
    return maxi;
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
    int m = maxConsecutiveOnes(a,n);
    cout << m;
}