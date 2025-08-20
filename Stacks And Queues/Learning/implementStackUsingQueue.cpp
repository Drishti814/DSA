#include<iostream>
#include<queue>
using namespace std;


class Stack{

    queue<int> q;

    public:
        Stack(){
        }
    
    //TC O(N)
    //SC O(size)
    void push(int x){
        int size = q.size();
        q.push(x);
        for(int i = 0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }

    //TC O(1)
    //SC O(size)
    int Top(){
        if (q.empty()) {
            cout << "Stack empty" << endl;
            return -1;
        }
        return q.front();
    }

    //TC O(1)
    //SC O(size)
    int pop(){
        if (q.empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int el = q.front();
        q.pop();
        return el;
    }

    //TC O(1)
    //SC O(size)
    int Size(){
        return q.size();
    }
};

int main(){
    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}