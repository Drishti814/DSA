#include<iostream>
#include<vector>
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

Node* deleteHead(Node* head){
    if(head==nullptr) return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==nullptr) return NULL;
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

int main(){
    vector<int> arr = {2,8,9,4};
    Node* head = arrayToLL(arr);
    cout << "before: ";
    traversalLL(head);
    cout  << endl;
    //Node* ans = deleteHead(head);
    Node* ans = deleteTail(head);
    cout << "after: ";
    traversalLL(ans);  
    
}
