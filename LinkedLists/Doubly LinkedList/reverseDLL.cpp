#include<iostream>
#include<vector>
#include<stack>
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

//brute froce
//TC O(2N)
//SC O(N)
Node* reverseDLL(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    stack<int> st;
    Node* temp = head;
    while(temp){
        st.push(temp->data);
        temp = temp->next; 
    }
    Node* tempo = head;
    while(tempo){
        tempo->data = st.top();
        st.pop();
        tempo = tempo->next;
    }
    return head;
}

//optimal
//TC O(N)
//SC O(1)
Node* reverseDLLOptimal(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=nullptr){
        prev = curr->back;
        curr->back = curr->next;
        curr->next = prev;
        curr = curr->back;
    }
    head = prev->back;
    return head;
}

int main(){
    vector<int> arr = {2,8,9,4};
    Node* head = arrayToDLL(arr);
    cout << "before: ";
    traversalDLL(head);
    cout  << endl;
    int val = 5;
    cout << "after: ";
    //Node* ans = reverseDLL(head);
    Node* ans = reverseDLLOptimal(head);
    traversalDLL(ans);     
}