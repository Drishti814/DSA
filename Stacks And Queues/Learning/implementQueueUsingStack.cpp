#include<iostream>
#include<stack>
using namespace std;

//fixed size

class Queue{

    stack<int> st1, st2;

    public:
        Queue(){
        }
    
    //TC O(2N)
    //SC O(2N)
    void push(int x){
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    //TC O(1)
    //SC O(1)
    int Top(){
        return st1.top();
    }

    //TC O(1)
    //SC O(1)
    int pop(){
        int el = st1.top();
        st1.pop();
        return el;
    }

    //TC O(1)
    //SC O(1)
    int Size(){
        return st1.size();
    }
};

//approach 2 - if push > pop & top statements
class q{

    stack<int> st1, st2;

    public:
        q(){
        }
    
    //TC O(1)
    //SC O(1)
    void push(int x){
        st1.push(x);
    }

    //TC O(N)
    //SC O(1)
    int Top(){
        if(!st2.empty()){
            return st2.top();
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }

    //TC O(N)
    //SC O(1)
    int pop(){
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int el = st2.top();
        st2.pop();
        return el;
    }

    //TC O(1)
    //SC O(1)
    int Size(){
        return st1.size() + st2.size();
    }
};

int main(){
    Queue q;
    q.push(6);
    q.push(3);
    q.push(7);
    cout << "Top of queue is before deleting any element " << q.Top() << endl;
    cout << "Size of queue before deleting any element " << q.Size() << endl;
    cout << "The element deleted is " << q.pop() << endl;
    cout << "Size of queue after deleting an element " << q.Size() << endl;
    cout << "Top of queue after deleting an element " << q.Top() << endl;
    return 0;
}