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
//SC O(N)
bool palindromeLL(Node* head){
    if(head == nullptr || head->next == nullptr) return true;
    Node* temp = head;
    stack<Node*> st;
    while(temp){
        st.push(temp);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(temp->data != st.top()->data) return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

Node* reverseLLRecursive(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* newHead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

//optimal
//TC O(2N)
//SC O(1)
bool palindromeLLOptimal(Node* head){
    if(head == nullptr || head->next == nullptr) return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLLRecursive(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second){
        if(first->data != second->data){
            reverseLLRecursive(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLLRecursive(newHead);
    return true;
}

int main(){
    vector<int> arr1 = {1,2,3,4,3,2,1};
    Node* head1 = arrayToLL(arr1);
    traversalLL(head1);
    cout << endl;
    //bool ans = palindromeLL(head1);
    bool ans = palindromeLLOptimal(head1);
    cout << ans;
}