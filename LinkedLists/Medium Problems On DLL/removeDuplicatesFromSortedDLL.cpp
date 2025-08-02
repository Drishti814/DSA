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

Node* findTail(Node* head){
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    return tail;
}

//optimal
//TC O(N)
//SC O(1)
Node* removeDuplicates(Node* head){
    Node* temp = head;
    while(temp && temp->next){
        Node* front = temp->next;
        while(front && front->data==temp->data){
            Node* duplicate = front;
            front = front->next;
            delete duplicate;
        }
        temp->next = front;
        if(front) front->back = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,1,1,2,2,3,4,5,5};
    Node* head = arrayToDLL(arr);
    cout << "before: ";
    traversalDLL(head);
    cout  << endl;
    cout << "after: ";
    Node* ans = removeDuplicates(head);
    traversalDLL(ans);
}