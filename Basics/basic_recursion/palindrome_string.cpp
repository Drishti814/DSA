#include<iostream>
using namespace std;

//TC - O(n/2) SC - O(n/2)

bool palindrome(int i, string str) {
    int n = str.size();
    if(i>=n/2) return true;
    if(str[i] != str[n-i-1]) return false;
    return palindrome(i+1,str);
}

int main(){\
    string st;
    cin >> st;
    cout << palindrome(0,st);
}