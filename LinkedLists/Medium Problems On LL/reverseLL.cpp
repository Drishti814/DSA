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
//TC O(2N)
//SC O(N)
Node* reverseLL(Node* head){
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
Node* reverseLLOptimal(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=nullptr){
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    head = prev;
    return head;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    cout << "after: ";   
    //Node* ans = reverseLL(head1);
    Node* ans = reverseLLOptimal(head1);
    traversalLL(ans);
}