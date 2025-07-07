#include<iostream>
#include<stack>
using namespace std;

//LIFO (last in first out)
//O(1)

int main(){
    stack<int> st;              //st = {}
    st.push(1);                 //st = {1}
    st.emplace(2);              //st = {2,1}
    cout << st.top() << endl;   //2
    st.pop();                   //st = {1}
    cout << st.top() << endl;   //1
    cout << st.size() << endl;  //1
    cout << st.empty() << endl; //false(0)

    stack<int> st1,st2;
    st1.swap(st2);
}