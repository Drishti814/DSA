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

Node* deleteHead(Node* head){
    if(head == nullptr || head->next == nullptr) return NULL;
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr || head->next == nullptr) return NULL;
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    Node* newtail = tail->back;
    newtail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deleteKth(Node* head, int k){
    if(head==nullptr) return NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev==nullptr && front == nullptr){
        return NULL;
    }
    else if(prev==nullptr){
        return deleteHead(head);
    }
    else if(front==nullptr){
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    delete temp;
    return head;
}

Node* deleteEl(Node* head, int el){
    if(head==nullptr) return NULL;
    Node* temp = head;
    while(temp){
        if(temp->data==el) break;
        temp = temp->next;
    }
    if(!temp){
        cout << "Not Found" << " ";
        return head;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev==nullptr && front == nullptr){
        delete temp;
        return NULL;
    }
    else if(prev==nullptr){
        head = head->next;
        head->back = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    else if(front==nullptr){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    delete temp;
    return head;
}

int main(){
    vector<int> arr = {2,8,9,4};
    Node* head = arrayToDLL(arr);
    cout << "before: ";
    traversalDLL(head);
    cout  << endl;
    cout << "after: ";
    //Node* ans = deleteHead(head);
    //Node* ans = deleteTail(head);
    //Node* ans = deleteKth(head,3);
    Node* ans = deleteEl(head,8);
    traversalDLL(ans);  
}