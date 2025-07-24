#include<iostream>
#include<vector>
using namespace std;

class Node{ 
    public: 
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public: 
    Node(int data1){
        data = data1;
        next = back = nullptr;
    }
};

Node* arrayToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp= new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void traversalDLL(Node* head){
    if(head==nullptr) return;
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//BEFORE NODE

Node* insertHead(Node* head,int val){
    if(head==nullptr) return new Node(val);
    Node* temp = new Node(val,head,nullptr);
    head->back = temp;
    head = head->back;
    return head;
}

//before tail
Node* insertTail(Node* head, int val){
    if(head==nullptr) return new Node(val);
    if(!head->next) return insertHead(head,val);
    Node* tail = head;
    while(tail->next!=nullptr){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* temp = new Node(val,tail,prev);
    tail->back = temp;
    prev->next = temp;
    return head;
}

//insert at tail
Node* insertAtTail(Node* head, int val){
    if(head==nullptr) return new Node(val);
    if(!head->next) return insertHead(head,val);
    Node* tail = head;
    while(tail->next!=nullptr){
        tail = tail->next;
    }
    Node* temp = new Node(val,nullptr,tail);
    tail->next = temp;
    return head;
}

Node* insertKth(Node* head, int k, int val){
    if(k==1) return insertHead(head,val);
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* insertBeforeEl(Node* head, Node* el, int val){
    Node* prev = el->back;
    Node* newNode = new Node(val,el,prev);
    prev->next = newNode;
    el->back = newNode;
    return head;
}

int main(){
    vector<int> arr = {2,8,9,4};
    Node* head = arrayToDLL(arr);
    cout << "before: ";
    traversalDLL(head);
    cout  << endl;
    int val = 5;
    cout << "after: ";
    //Node* ans = insertHead(head,val);
    //Node* ans = insertTail(head,val);
    //Node* ans = insertAtTail(head,val);
    //Node* ans = insertKth(head,3,val);
    Node* ans = insertBeforeEl(head,head->next,val);
    traversalDLL(ans);     
}