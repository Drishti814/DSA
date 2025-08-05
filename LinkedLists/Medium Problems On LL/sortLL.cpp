#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
//TC(2N + logN)
//SC O(N)
Node* sortLL(Node* head){
    vector<int> arr;
    Node* temp = head;
    while(temp){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    temp = head;
    int i = 0;
    while(temp){
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

Node* middleElement(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeTwoLL(Node* list1, Node* list2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(list1 && list2){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;
    return dummy->next;
}

Node* sortLLOptimal(Node* head){
    if(!head || !head->next) return head;
    Node* middle = middleElement(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr;
    left = sortLLOptimal(left);
    right = sortLLOptimal(right);
    return mergeTwoLL(left,right);
}

int main(){
    vector<int> arr1 = {3,2,5,1,6,4};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    cout << "after: ";
    //Node* ans = sortLL(head1);
    Node* ans = sortLLOptimal(head1);
    traversalLL(ans);
}