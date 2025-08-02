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
int lengthCycle(Node *head){
    Node* temp = head;
    int val = 0;
    unordered_map<Node*, int> mpp;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return val - mpp[temp];
        }
        mpp[temp] = val;
        val++;
        temp = temp->next;
    }
    return 0;
}

int lengthLoop(Node* slow,Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow!=fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

//optimal
//TC O(N)
//SC O(1)
int lengthCycleOptimal(Node *head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return lengthLoop(slow,fast);
    }
    return 0;
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
    cout << "Loop length: ";
    //int ans = lengthCycle(head);
    int ans = lengthCycleOptimal(head);
    cout << ans;
}