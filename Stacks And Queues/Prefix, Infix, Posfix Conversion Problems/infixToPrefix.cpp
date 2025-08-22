#include<iostream>
#include<climits>
#include<stack>
#include<algorithm>
using namespace std;

int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    return -1;
}

//TC O(3N)
//SC O(N)
void infixToPrefix(string s){
    int n = s.length();
    reverse(s.begin(),s.end());
    for(int i = 0;i<n;i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    int i = 0;
    stack<char> st;
    string ans = "";
    while(i<n){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            ans += s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() &&
             ((s[i]!='^' && (priority(s[i])<= priority(st.top()))) ||
              (s[i]=='^' && priority(s[i]) < priority(st.top())))){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    
    cout << "Prefix expression: " << ans << endl;
}

int main(){
    string exp = "(p+q)*(c-d)";
    cout << "Infix expression: " << exp << endl;
    infixToPrefix(exp);
}