#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

//brute force - loop from 2 to N and check every integer if it is prime or not
//TC O(N*sqrt(N))
//SC O(1)

//optimal
//TC O(N+log(logn)+N)
//SC O(N)
void primesTillGivenNum(int n){
    vector<int> prime(n+1,1);
    prime[0] = prime[1] = 0; 
    for(int i = 2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j = i*i;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }
    for(int i = 2;i<=n;i++){
        if(prime[i]==1) cout << i << " ";
    }
}

//counts primes less than or equal to n
int countPrimes(int n){
    if (n < 2) return 0;
    int cnt = 0;
    vector<int> prime(n+1,1);
    prime[0] = 0; 
    prime[1] = 0;
    for(int i = 2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j = i*i;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }
    for(int i = 2;i<=n;i++){
        if(prime[i]==1) cnt++;
    }
    return cnt;
}

int main(){
    int n;   
    cin >> n;
    int cnt = countPrimes(n);
    cout << cnt << endl;
    primesTillGivenNum(n);
}