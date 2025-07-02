#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n1,n2;
    int gcd = 1;
    cin >> n1 >> n2;

    //Brute force methods
    //O(n)
    for(int i=1; i<=min(n1,n2);i++){
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;
        }
    }
    //cout << gcd;

    for(int i=min(n1,n2); i>=1;i--){
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;
            break;
        }
    }
    //cout << gcd;

    //Euclidean Algorithm
    //GCD(a,b) = (a-b,b) if a>b
    //implies GCD(a,b) = (a%b,b) if a>b
    //O(log(min(a,b))) where base is variable
    while(n1>0 && n2>0){
        if(n1>n2){
            n1 = n1 % n2;
        }
        if(n2>n1){
            n2 = n2 % n1;
        }
        if(n1 == 0) cout << n2;
        else cout << n1;
    }

}