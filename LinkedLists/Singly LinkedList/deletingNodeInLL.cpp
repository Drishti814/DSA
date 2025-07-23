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
    if(head==nullptr) return head;
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

Node* deleteKth(Node* head, int k){
    if(head==nullptr) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=nullptr){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteEl(Node* head, int el){
    if(head==nullptr) return head;
    if(head->data==el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=nullptr){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
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
    //Node* ans = deleteHead(head);
    //Node* ans = deleteTail(head);
    //Node* ans = deleteKth(head,3);
    Node* ans = deleteEl(head,8);
    cout << "after: ";
    traversalLL(ans);  
    
}
