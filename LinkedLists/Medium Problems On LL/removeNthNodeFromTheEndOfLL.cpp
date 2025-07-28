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

//optimal
Node* removeNthfromEndOptimal(Node* head, int n){
    Node* fast = head;
    for(int i = 0;i<n;i++) fast = fast->next;
    if(fast==nullptr){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* slow = head;
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    Node* del = slow->next;
    slow->next = slow->next->next;
    delete del;
    return head;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    cout << "after: ";   
    Node* ans = removeNthfromEndOptimal(head1,2);
    traversalLL(ans);
}