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

Node* addTwoNumbers(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;
    while(temp1 || temp2){
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummy->next;
}

int main(){
    vector<int> arr1 = {3,5};
    vector<int> arr2 = {4,5,9,9};
    Node* head1 = arrayToLL(arr1);
    cout << "LL 1: ";
    traversalLL(head1);
     cout  << endl;
    Node* head2 = arrayToLL(arr2);
    cout << "LL 2: ";
    traversalLL(head2);
    cout  << endl;
    cout << "LL 3: ";
    Node* ans = addTwoNumbers(head1, head2);
    traversalLL(ans);
}