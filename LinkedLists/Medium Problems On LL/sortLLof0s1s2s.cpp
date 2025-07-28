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

//brute force
//TC O(2N)
//SC O(1)
Node* sort0s1s2s(Node* head){
    if(!head || !head->next) return head;
    Node* temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while(temp){ 
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }
    Node* curr = head;
    while(curr){
        if(cnt0){
            curr->data = 0;
            cnt0--; 
        }
        else if(cnt1){
            curr->data = 1;
            cnt1--; 
        }
        else{
            curr->data = 2;
            cnt2--; 
        }
        curr = curr->next;
    }
    return head;
}

//optimal
//TC O(N)
//SC O(1)
Node* sort0s1s2sOptimal(Node* head){
    if(!head || !head->next) return head;
    Node* dummy0 = new Node(-1);
    Node* zero = dummy0;
    Node* dummy1 = new Node(-1);
    Node* one = dummy1;
    Node* dummy2 = new Node(-1);
    Node* two = dummy2;
    Node* temp = head;
    while(temp){ 
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = dummy1->next ? dummy1->next : dummy2->next; 
    one->next = dummy2->next;
    two->next = nullptr;
    Node* newHead = dummy0->next;
    delete dummy0;
    delete dummy1;
    delete dummy2;
    return newHead;
}

int main(){
    vector<int> arr1 = {1,0,1,2,0,2,1};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    cout << "after: ";   
    //Node* ans = sort0s1s2s(head1);
    Node* ans = sort0s1s2sOptimal(head1);
    traversalLL(ans);
}