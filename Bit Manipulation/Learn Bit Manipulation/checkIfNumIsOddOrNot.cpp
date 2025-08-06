#include<iostream>
#include<algorithm>
using namespace std;

void checkOdd(int n){
    if(n&1) cout << "odd";  //n&1==1 then odd else if 0 then even
    else cout << "even";
}

int main(){
    int n;
    cin >> n;
    checkOdd(n);
}