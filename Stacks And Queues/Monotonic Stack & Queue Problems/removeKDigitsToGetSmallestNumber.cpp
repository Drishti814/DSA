#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

//3 edge cases
//1. k==n
//2. zeroes at the front
//3. if k digits are not removed eg 12345 and k==2 remove last k digits i.e. num==123
//TC O(3N+K)
//SC O(2N)
string removeKDigits(string num, int k){
    int n = num.length();
    if(k==n) return "0";        //1 
    stack<char> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && k>0 && (num[i]-'0')<(st.top()-'0')){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k>0){                 //3            
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    while(ans.size()!=0 && ans.back()=='0'){        //2          
        ans.pop_back();
    } 
    reverse(ans.begin(),ans.end());
    if (ans.empty()) return "0";
    return ans;
}

int main(){
    string num = "1432219";
    string ans = removeKDigits(num,3);
    cout << ans;
}