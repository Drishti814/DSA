#include<iostream>
using namespace std;

//not fixed size - O(N) dynamic size

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

class Queue{

    int size;
    Node* start;
    Node* end;

    public:
        Queue(){
            size = 0;
            start = nullptr;
            end = nullptr;
        }
    
    //TC O(1)
    //SC O(1)
    void push(int x){
        Node* temp = new Node(x);
        if(start==nullptr){
            start = temp;
            end = temp;
        }
        else{
            end->next = temp;
            end = temp;
        }
        size++;
    }

    //TC O(1)
    //SC O(1)
    int Top(){
        if(start==nullptr){
            cout << " queue empty";
            return -1;
        }
        return start->data;
    }

    //TC O(1)
    //SC O(1)
    int pop(){
        if(start==nullptr){
            cout << " Queue Empty";
            return -1;
        }
        int el = start->data;
        Node* temp = start;
        start = start->next;
        delete temp;
        size--;
        return el;
    }

    //TC O(1)
    //SC O(1)
    int Size(){
        return size;
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