#include<iostream>
#include<algorithm>
using namespace std;

//TC O(len)
//SC O(1)
int convertToDecimal(string s){
    int len = s.length();
    if(len == 0) return 0;
    int num = 0;
    int pow2 = 1;
    for(int i = len - 1;i>=0;i--){
        if(s[i]=='1'){
            num = num+pow2;
        }
        pow2 = pow2*2;
    }
    return num;
}

int main(){
    string s;
    cin >> s;
    int n = convertToDecimal(s);
    cout << "the decimal conversion of the string is:" << n;
}