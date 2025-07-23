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

Node* insertHead(Node* head,int val){
    Node* temp = new Node(val,head);
    head = temp;
    return head;
}

Node* insertTail(Node* head, int val){
    if(head==nullptr) return new Node(val);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new Node(val) ;
    return head;
}

Node* insertKth(Node* head, int k, int val){
    if(head==nullptr){
        if(k==1){
            return new Node(val);
        }
        else return head;
    }
    if(k==1){
        Node* temp = new Node(val,head);
        head = temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=nullptr){
        cnt++;
        if(cnt == k - 1){
            Node* el = new Node(val,temp->next);
            temp->next = el;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeEl(Node* head, int el, int val){
    if(head==nullptr) return head;
    if(head->data==el){
        return new Node(val,head);
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        if(temp->next->data == el){
            Node* element = new Node(val,temp->next);
            temp->next = element;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2,8,9,4};
    Node* head = arrayToLL(arr);
    cout << "before: ";
    traversalLL(head);
    cout  << endl;
    int val = 5;
    //Node* ans = insertHead(head,val);
    //Node* ans = insertTail(head,val);
    //Node* ans = insertKth(head,3,val);
    Node* ans = insertBeforeEl(head,4,val);
    cout << "after: ";
    traversalLL(ans);     
}