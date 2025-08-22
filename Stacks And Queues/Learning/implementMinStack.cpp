#include<iostream>
#include<climits>
#include<stack>
using namespace std;

//brute force - iterating through the whole stack and finding the minimum
//TC O(N)

//better
//TC O(1)
//SC O(2N)
class Stack{
    stack<pair<int,int>> st;
    public:
        Stack(){
        }
        void push(int val){
            if(st.empty()){
                st.push({val,val});
            }
            else{
                st.push({val,min(val,st.top().second)});
            }
        }

        int getMin(){
            return st.top().second;
        }

        int Top(){
            return st.top().first;
        }
        int pop(){
            int el = st.top().first;
            st.pop();
            return el;
        }
};

//optimal
//TC O(1)
//SC O(N)
class MinStack {
public:
    stack<long long> st;
    long long minn;
    MinStack() {
        minn = LLONG_MAX;
    }
    
    void push(int val) {
        long long v = val;
        if(st.empty()){
            minn = v;
            st.push(v);
        }
        else{
            if(v>minn) st.push(v);
            else{
                st.push(2*v - minn);
                minn = v;
            } 
        }
    }
    
    void pop() {
    if(st.empty()){
            return ;
        }
        long long x = st.top();
        st.pop();
        if(x<minn){
            minn = (2*minn - x);
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        long long x = st.top();
        if(minn < x) return x;
        return minn;
    }
    
    int getMin() {
        return minn;
    }
};

int main(){
    //Stack s;
    MinStack s;
    s.push(6);
    s.push(10);
    s.push(4);
    cout << "min element in the stack is " << s.getMin() << endl;
    s.pop();
    cout << "Min of stack after deleting an element " << s.getMin() << endl;
    return 0;
}