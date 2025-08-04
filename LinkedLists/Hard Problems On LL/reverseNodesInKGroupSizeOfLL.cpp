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

Node* reverseLLRecursive(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* newHead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

Node* findkthNode(Node* head, int k){
    Node* temp = head;
    k-=1;
    while(temp && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

//optimal
//TC O(2N)
//SC O(1)
Node* reverseByGroups(Node* head, int k){
    if(!head || k == 1) return head;
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        Node* kthNode = findkthNode(temp,k);
        if(kthNode==NULL){
            if(prev) prev->next = temp;
            break;
        }
        Node* front = kthNode->next;
        kthNode->next = NULL;
        reverseLLRecursive(temp);
        if(temp==head){
            head = kthNode;
        }
        else{
            prev->next = kthNode;
        }
        prev = temp;
        temp = front;
    }
    return head;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    cout << "after: ";
    Node* ans = reverseByGroups(head1,3);
     traversalLL(ans);
}