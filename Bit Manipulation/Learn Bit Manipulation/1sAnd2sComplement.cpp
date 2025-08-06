#include<iostream>
#include<algorithm>
using namespace std;

//TC O(len)
//SC O(len)
string onesComplement(string s){
    string st = "";
    int len = s.length();
    for(int i = 0; i < len;i++){
        if(s[i]=='1') st += '0';
        else st+='1';
    }
    return st;
}

//TC O(len)
//SC O(len)
string twosComplement(string s){
    string st = onesComplement(s);
    int len = st.length();
    for(int i = len-1; i>=0;i--){
        if(st[i]=='0'){
            st[i]='1';
            break;
        } 
        else st[i] = '0';
    }
    if(st[0]=='0') return st;
    else  return '1'+st;
}

int main(){
    string s;
    cin >> s;
    string one = onesComplement(s);
    string two = twosComplement(s);
    cout << "the 1s Complement of the string is:" << one << endl;
    cout << "the 2s Complement of the string is:" << two;
}