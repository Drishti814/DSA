#include<iostream>
using namespace std;

class Stack{

    int size;
    int * arr;
    int top;

    public:
        Stack(){
            top = -1;
            size = 10;
            arr = new int[size];
        }
    
    //TC O(1)
    //SC O(size)
    void push(int x){
        if(top==size-1){
            cout << " Stack Overflow";
            return;
        }
        top++;
        arr[top] = x;
    }

    //TC O(1)
    //SC O(size)
    int Top(){
        if(top==-1){
            cout << " Stack empty";
            return -1;
        }
        return arr[top];
    }

    //TC O(1)
    //SC O(size)
    int pop(){
        if(top==-1){
            cout << " Stack Underflow";
            return -1;
        }
        int el = arr[top];
        top--;
        return el;
    }

    //TC O(1)
    //SC O(size)
    int Size(){
        return top+1;
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