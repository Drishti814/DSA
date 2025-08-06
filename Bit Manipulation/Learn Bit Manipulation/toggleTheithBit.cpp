#include<iostream>
#include<algorithm>
using namespace std;

int toggleTheBit(int n, int i){
    int ans = ((n^(1<<i)));
    return ans;
}

int main(){
    int n;
    cin >> n;
    int ans = toggleTheBit(n,2);
    cout << "toggle the ith bit:" << ans << endl;
}