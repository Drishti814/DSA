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
//TC O(N1+N2)
//SC O(N1) or O(N2)
Node* intersectionPointBetter1(Node* head1, Node* head2){
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

Node* collisionPoint(Node* head1, Node* head2, int d){
    while(d){
        d--;
        head2 = head2->next;
    }
    while(head1!=head2){
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

//better - differences
//TC O(N1+N2)
//SC O(N1) or O(N2)
Node* intersectionPointBetter2(Node* head1, Node* head2){
    Node* temp1 = head1;
    int cnt1 = 0;
     while(temp1){
        cnt1++;
        temp1 = temp1->next;
     }
    Node* temp2 = head2;
    int cnt2 = 0;
    while(temp2){
        cnt2++;
        temp2 = temp2->next;
    }
    if(cnt2 > cnt1) return collisionPoint(head1,head2,cnt2-cnt1); //(smaller,bigger,diff)
    return collisionPoint(head2,head1,cnt1-cnt2);
}

Node* intersectionPointOptimal(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != temp2){
        temp1 = temp1==NULL ? head2 : temp1->next;
        temp2 = temp2==NULL ? head1 : temp2->next;
    }
    return temp1;
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
    //Node* ans = intersectionPointBetter1(head1,head2);
    //Node* ans = intersectionPointBetter2(head1,head2);
    Node* ans = intersectionPointOptimal(head1,head2);
    cout << ans->data;
}