#include<iostream>
using namespace std;

//TC- O(n) SC- O(n) 

int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

int main(){
    int n;
    cin >> n;
    int fact = factorial(n);
    cout << fact << endl; 
}