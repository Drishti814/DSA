#include<iostream>
#include<climits>
#include<stack>
using namespace std;

//we can to prefix to infix then infix to postfix

int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    return -1;
}

//TC O(N+N)
//SC O(N)
void prefixToPostfix(string s){
    int n = s.length();
    int i = n-1;
    stack<string> st;
    string ans = "";
    while(i>=0){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string exp = t1+t2+string(1,s[i]);
            st.push(exp);
        } 
        i--;
    }
    cout << "Postfix expression: " << st.top() << endl;
}

int main(){
    string exp = "*+pq-mn";
    cout << "Prefix expression: " << exp << endl;
    prefixToPostfix(exp);
}