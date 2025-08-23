#include<iostream>
#include<climits>
#include<stack>
using namespace std;

//we can to postfix to infix then infix to prefix

int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    return -1;
}

//TC O(N+N)
//SC O(N)
void postfixToPrefix(string s){
    int n = s.length();
    int i = 0;
    stack<string> st;
    string ans = "";
    while(i<n){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string exp = string(1,s[i])+t2+t1;
            st.push(exp);
        }
        i++;
    }
    cout << "Prefix expression: " << st.top() << endl;
}

int main(){
    string exp = "ab-de+f*/";
    cout << "Postfix expression: " << exp << endl;
    postfixToPrefix(exp);
}