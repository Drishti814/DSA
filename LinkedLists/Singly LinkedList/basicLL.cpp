#include<iostream>
#include<vector>
using namespace std;

class Node{     //struct Node(use class than struct for OOPs)
    public: 
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public: //multiple constructors can be used
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


int main(){
    vector<int> arr = {1,2,3,4};
    Node x = Node(arr[0],nullptr);
    cout << x.data << " " << x.next << endl ;   //gives node value 
    Node* y = new Node(arr[2]); //gives memory address
    cout << y << endl;
    cout << y->data;    //this will give data
}

//memory taken depends on system whether it is 32 bit or 64 bit