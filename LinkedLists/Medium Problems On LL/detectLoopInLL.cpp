#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
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

//brute force
//TC O(N*2*log(N))
//SC O(N)
bool hasCycle(Node *head){
    Node* temp = head;
    unordered_map<Node*, int> mpp;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

//optimal
//TC O(N)
//SC O(1)
bool hasCycleOptimal(Node *head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 
    cout << "Loop: ";
    //bool ans = hasCycle(head);
    bool ans = hasCycleOptimal(head);
    if(ans==1) cout << "yes";
    else cout << "no";
}