//functional

#include<iostream>
using namespace std;

int sum_n(int n){
    if(n==0) return 0;
    return n + sum_n(n-1);
}

int main(){
    int n;
    cin >> n;
    int sum = sum_n(n);
    cout << sum << endl; 
}

/*
//parameterized
#include<iostream>
using namespace std;

void sum_n(int i, int sum){
    if(i<1){
        cout << sum;
        return;
    } 
    sum_n(i-1 ,sum + i);
}

int main(){
    int n;
    cin >> n;
    sum_n(n,0); 
}
*/