#include<iostream>
using namespace std;

class Queue{

    int size;
    int * arr;
    int start;
    int end;
    int currSize;

    public:
        Queue(){
            size = 10;
            arr = new int[size];
            start = -1;
            end = -1;
            currSize = 0;
        }
    
    //TC O(1)
    //SC O(size)
    void push(int x){
        if(currSize==size){
            cout << " Queue Full";
            return;
        }
        if(currSize==0){
            start = 0;
            end = 0;
        } 
        else{
            end = (end+1)%size;
        }
        arr[end] = x;
        currSize++;
    }

    //TC O(1)
    //SC O(size)
    int Top(){
        if(currSize==0){
            cout << " queue empty";
            return -1;
        }
        return arr[start];
    }

    //TC O(1)
    //SC O(size)
    int pop(){
        if(currSize==0){
            cout << " Queue Empty";
            return -1;
        }
        int el = arr[start];
        if(currSize==1){
            start = -1;
            end = -1;
        }
        else{
            start = (start+1)%size;
        }
        currSize--;
        return el;
    }

    //TC O(1)
    //SC O(size)
    int Size(){
        return currSize;
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