#include<iostream>
#include<algorithm>
using namespace std;

int SetTheBit(int n, int i){
    int ans = ((n|(1<<i)));
    return ans;
}

int unsetTheBit(int n, int i){
    int ans = ((n&(~(1<<i))));
    return ans;
}

int main(){
    int n;
    cin >> n;
    int ans = SetTheBit(n,2);
    cout << "set the ith bit:" << ans << endl;
    int a = unsetTheBit(n,2);
    cout << "unset the ith bit:" << a;
}