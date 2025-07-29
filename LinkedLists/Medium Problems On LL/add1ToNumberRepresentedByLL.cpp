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

Node* reverseLLRecursive(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* newHead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

//brute force
//TC O(3N)
//SC O(1)
Node* addOne(Node* head){
    head = reverseLLRecursive(head);
    Node* temp = head;
    int carry = 1;
    while(temp){
        temp->data = temp->data + carry;
        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry == 1){
        Node* newHead = new Node(1);
        head = reverseLLRecursive(head);
        newHead->next = head;
        return newHead;
    }
    head = reverseLLRecursive(head);
    return head;
}

int helper(Node* temp){
    if(temp==nullptr){
        return 1;
    }
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}

//optimal
//TC O(N)
//SC O(N)
Node* addOneOptimal(Node* head){
    int carry = helper(head);
    if(carry == 1){
        Node* newHead = new Node(1);
        head = reverseLLRecursive(head);
        newHead->next = head;
        return newHead;
    }
    return head;
}

int main(){
    vector<int> arr1 = {9,9,9,9};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    //Node* ans = addOne(head1);
    Node* ans = addOneOptimal(head1);
    cout << "after: ";
    traversalLL(ans);
}