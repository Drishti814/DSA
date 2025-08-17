#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

void primeFactorization(vector<int> &queries){
    int N = 1e5;
    int q = queries.size();
    vector<int> spf(N+1);
    for(int i = 1;i<=N;i++){
        spf[i] = i;
    }
    for(int i = 2;i*i<=N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=N;j=j+i){
                if(spf[j]==j) spf[j]=i;  
            }
        }
    }
    for(int i = 0;i<q;i++){
        int n = queries[i];
        while(n!=1){
            cout << spf[n] << " ";
            n = n/spf[n];
        }
        cout << endl;
    }
}

int main() {
    vector<int> queries  = {30,17,25,16};
    primeFactorization(queries);
}