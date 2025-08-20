#include<iostream>
using namespace std;

//size not fixed

class Node{     
    public: 
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public: 
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class Stack{

    int size;
    Node * top;

    public:
        Stack(){
            top = NULL;
            size = 0;
        }
    
    //TC O(1)
    //SC O(size)
    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    //TC O(1)
    //SC O(size)
    int Top(){
        return top->data;
    }

    //TC O(1)
    //SC O(size)
    int pop(){
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int el = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return el;
    }

    //TC O(1)
    //SC O(size)
    int Size(){
        return size;
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