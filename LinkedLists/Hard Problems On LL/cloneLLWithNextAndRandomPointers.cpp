#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;

class Node{    
    public: 
    int data;
    Node* next;
    Node* random;

    public:
    Node(int data1, Node* next1, Node* random1){
        data = data1;
        next = next1;
        random = random1;
    }

    public: 
    Node(int data1){
        data = data1;
        next = nullptr;
        random = nullptr;
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

void printClonedLL(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        head = head->next;  
    }
}

//brute force
//TC O(2N)
//SC O(N)+O(N)
Node* cloneLL(Node* head){
    Node* temp = head;
    map<Node*,Node*> mpp;
    while(temp){
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while(temp){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

//brute force
//TC O(3N)
//SC O(N)
Node* cloneLLOptimal(Node* head){
    Node* temp = head;
    Node* copyNode = NULL;
    while(temp){
        copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
    temp = head;
    while(temp){
        copyNode = temp->next;
        if(temp->random) copyNode->random = temp->random->next;
        else copyNode->random = NULL;
        temp = temp->next->next;
    }
    Node* dummy = new Node(-1);
    Node* res = dummy;
    temp = head;
    while(temp){
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummy->next;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;
    cout << "before: " << endl;
    printClonedLL(head);
    cout << "after: " << endl;
    //Node* clonedLL = cloneLL(head);
    Node* clonedLL = cloneLLOptimal(head);
    printClonedLL(clonedLL);
}