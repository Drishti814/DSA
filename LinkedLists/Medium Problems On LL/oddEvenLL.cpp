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
Node* oddEven(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    vector<int> arr;
    Node* odd = head;
    Node* even = head->next;
    while(odd && odd->next){
        arr.push_back(odd->data);
        odd = odd->next->next;
    }
    if(odd) arr.push_back(odd->data);
    while(even && even->next){
        arr.push_back(even->data);
        even = even->next->next;
    }
    if(even) arr.push_back(even->data);
    Node* temp = head;
    for(int i = 0;i<arr.size();i++){
        temp->data = arr[i];
        temp= temp->next;
    }
    return head;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5,6};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    cout << "after: ";   //after sum
    Node* ans = oddEven(head1);
    traversalLL(ans);
}