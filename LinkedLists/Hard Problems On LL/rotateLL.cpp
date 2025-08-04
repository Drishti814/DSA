#include<iostream>
#include<vector>
#include<stack>
using namespace std;

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

Node* arrayToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traversalLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* rotateLL(Node* head, int k){
    if(!head || !head->next || k == 0) return head;
    Node* tail = head;
    int len = 1;
    while(tail->next){
        len++;
        tail = tail->next;
    }
    if(k%len==0) return head;
    k = k % len;
    tail->next = head;
    int rem = len - k;
    Node* temp = tail;
    while(rem!=0){
        rem--;
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5,6};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    cout << "after: ";
    Node* ans = rotateLL(head1,3);
     traversalLL(ans);
}