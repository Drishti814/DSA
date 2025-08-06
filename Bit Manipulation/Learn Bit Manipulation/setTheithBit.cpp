#include<iostream>
#include<algorithm>
using namespace std;

string convertToBinary(int n){
    if(n==0) return "0";
    string s = "";
    while(n != 1){
        if(n%2==1) s+='1';
        else s+='0';
        n = n/2;
    }
    s+='1';
    reverse(s.begin(),s.end());
    return s;
}

int SetTheBit(int n, int i){
    int ans = ((n|(1<<i)));
    return ans;
}

int main(){
    int n;
    cin >> n;
    int ans = SetTheBit(n,2);
    cout << ans;
}