#include<iostream>
using namespace std;

//TC- O(2^n) approx exponential

int fib(int n) {
        if(n<=1) return n;
        else return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin >> n;
    int fib_sum = fib(n);
    cout << fib_sum << endl; 
}