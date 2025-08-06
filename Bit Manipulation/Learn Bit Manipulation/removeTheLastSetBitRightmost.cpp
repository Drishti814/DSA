#include<iostream>
#include<algorithm>
using namespace std;

int removeLastSetBit(int n){
    int ans = n&(n-1);
    return ans;
}

int main(){
    int n;
    cin >> n;
    int ans = removeLastSetBit(n);
    cout << "after removing the last set bit: " << ans << endl;
}