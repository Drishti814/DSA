#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//brute force 
//TC O(n^3)
//SC O(1)
int countSubarrayXOR(vector<int> &a, int n, int K){
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int Xor = 0;
            for(int k = i;k<=j;k++){
                Xor = Xor ^ a[k];
            }
            if(Xor==K) count++; 
        }
    }
    return count;
}

//better 
//TC O(n^2)
//SC O(1)
int countSubarrayXORBetter(vector<int> & a, int n, int K){
    int count = 0;
    for(int i = 0;i<n;i++){
        int Xor = 0;
        for(int j = i;j<n;j++){
            Xor = Xor ^ a[j];
            if(Xor==K) count++;
        }
   }
   return count;
}

//optimal 
//TC O(nlogn) map
//TC O(n*1) if unordered map O(n*n) worst case umap
//SC O(n)
int countSubarrayXOROptimal(vector<int> &a, int n, long long K){
    int count = 0;
    int xr = 0;
    unordered_map<int,int> mpp;
    mpp[xr]++;
    for(int i = 0;i<n;i++){
        xr = xr ^ a[i];
        int x = xr ^ K;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
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
    int K;
    cin >> K;
    //int m = countSubarrayXOR(a,n,K);
    //int m = countSubarrayXORBetter(a,n,K);
    int m = countSubarrayXOROptimal(a,n,K);
    cout << m;
}