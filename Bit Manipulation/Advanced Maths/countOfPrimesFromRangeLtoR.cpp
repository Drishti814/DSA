#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

bool checkPrime(int num){
    if (num < 2) return false;
    int count = 0;
    for(int i = 1;i<=sqrt(num);i++){
        if(num % i == 0){
            count+=1;
            if(num/i != i){
                count+=1;
            }
            if(count > 2) break;
        }
    }
    if(count == 2){
        return true;
    }
    return false;
}

//brute force
///TC O(Q × (R-L+1) × √N) ~ in terms of cube
void solve(vector<pair<int,int>> &queries){
    int q = queries.size();
    for(int i = 0;i<q;i++){
        int L = queries[i].first;
        int R = queries[i].second;
        int cnt = 0;
        for(int j = L;j<=R;j++){
            if(checkPrime(j)) cnt++;
        }
        cout << cnt << endl;
    }
}

vector<int> getSieve(int n){
    vector<int> prime(n+1,1);
    prime[0] = prime[1] = 0; 
    for(int i = 2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j = i*i;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }
    return prime;
}

//better
///TC O(Q × (R-L+1))
void solveBetter(vector<pair<int,int>> &queries){
    int N = 1e6;
    vector<int> prime = getSieve(N);
    int q = queries.size();
    for(int i = 0;i<q;i++){
        int L = queries[i].first;
        int R = queries[i].second;
        int cnt = 0;
        for(int j = L;j<=R;j++){
            if(prime[j]==1) cnt++;
        }
        cout << cnt << endl;
    }
}

//optimal
//TC O(10^6*log(log(10^6))+10^6+Q)
void solveOptimal(vector<pair<int,int>> &queries){
    int N = 1e6;
    vector<int> prime = getSieve(N);
    int q = queries.size();
    int cnt = 0;
    for(int i = 2;i<=N;i++){
        cnt = cnt + prime[i];
        prime[i] = cnt;
    }
    for(int i = 0;i<q;i++){
        int L = queries[i].first;
        int R = queries[i].second;
        cout << prime[R] - prime[L-1] << endl;
    }
}

int main() {
    vector<pair<int, int>> queries = {
        {2, 10},
        {3, 15},
        {1, 5}
    };
    //solve(queries);
    //solveBetter(queries);
    solveOptimal(queries);
}