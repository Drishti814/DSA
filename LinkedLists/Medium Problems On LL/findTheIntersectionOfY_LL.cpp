#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
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

void insertNode(Node* &head,int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return;
}

void traversalLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//brute force
//TC O(N1*N2)
//SC O(1)
Node* intersectionPoint(Node* head1, Node* head2){
    while(head1!=nullptr){
        Node* temp = head2;
        while(temp){
            if(temp==head1) return temp;
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return NULL;
}

//better - hashing
Node* intersectionPointBetter(Node* head1, Node* head2){
    unordered_set<Node*> st;
    while(head1){
        st.insert(head1);
        head1 = head1->next;
    }
    while(head2){
        if(st.find(head2)!=st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}

int main(){
    Node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);  //intersects at 2
    insertNode(head,4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = NULL;
    insertNode(headSec,3);
    Node* head2 = headSec;  
    headSec->next = head;  
    cout << "LL 1: ";
    traversalLL(head1);
     cout  << endl;
    cout << "LL 2: ";
    traversalLL(head2);
    cout  << endl;
    //Node* ans = intersectionPoint(head1,head2);
    Node* ans = intersectionPointBetter(head1,head2);
    cout << ans->data;
}