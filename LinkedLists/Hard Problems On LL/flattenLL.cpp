#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Node{    
    public: 
    int data;
    Node* next;
    Node* child;

    public:
    Node(int data1, Node* next1, Node* child1){
        data = data1;
        next = next1;
        child = child1;
    }

    public: 
    Node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;
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

void traversalChildLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->child;
    }
}

void printOriginalLL(Node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;
        if (head->child) {
            cout << " -> ";
            printOriginalLL(head->child, depth + 1);
        }
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

Node* arraytoChildLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->child = temp;
        mover = temp;
    }
    return head;
}

//brute force
//TC O(2*M*N + 2*M*N*log(M*N))
//SC O(M*N)
Node* flattenLL(Node* head){
    vector<int> arr;
    Node* temp = head;
    while(temp){
        Node* t2 = temp;
        while(t2){
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    return arraytoChildLL(arr);
}

Node* mergeTwoLL(Node* list1, Node* list2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(list1 && list2){
        if(list1->data < list2->data){
            temp->child = list1;
            temp = list1;
            list1 = list1->child;
        }
        else{
            temp->child = list2;
            temp = list2;
            list2 = list2->child;
        }
    }
    if(list1) temp->child = list1;
    else temp->child = list2;
    if(dummy->child) dummy->child->next = nullptr; 
    return dummy->child;
}

//optimal
//TC O(2*M*N)
//SC O(1)
Node* flattenLLOptimal(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node* mergedHead =flattenLLOptimal(head->next);
    head = mergeTwoLL(head,mergedHead);
    return head;
}

int main(){
    Node* head = new Node(5);
    head->child = new Node(14);
    head->next = new Node(3);
    head->next->child = new Node(4);
    head->next->next = new Node(12);
    head->next->next->child = new Node(13);
    head->next->next->child->child = new Node(20);
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);
    cout << "before: ";
    printOriginalLL(head,0);
    cout << endl;
    cout << "after: ";
    //Node* ans = flattenLL(head);
    Node* ans = flattenLLOptimal(head);
    traversalChildLL(ans);
}