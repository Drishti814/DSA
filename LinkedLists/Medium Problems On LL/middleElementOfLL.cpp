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

//brute froce
//TC O(N+N/2)
//SC O(1)
Node* middleElement(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    int midEl = (cnt/2)+1;
    Node* mid = head;
    while(mid){
        midEl--; 
        if(midEl==0) break;
        mid = mid->next;
    }
    return mid;
}

//optimal - tortoise hare method
//TC O(N/2)
//SC O(1)
Node* middleElementOptimal(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5,6};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    cout << "after: ";   
    //Node* ans = middleElement(head1);
    Node* ans = middleElementOptimal(head1);
    cout << ans->data;
}