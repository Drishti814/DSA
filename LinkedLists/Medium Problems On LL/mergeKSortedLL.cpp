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
//TC O(2*M*N+M*N*Log(M*N))
//SC O(2*M*N)
Node* mergeLL(vector<Node*> lists){
    vector<int> arr;
    for(int i = 0;i<lists.size();i++){
        Node* temp = lists[i];
        while(temp){
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(arr.begin(),arr.end());
    Node* head = arrayToLL(arr);
    return head;
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

//better
//TC O(N*K(K+1)/2) ~ O(N^3)
//SC O(1)
Node* mergeLLBetter(vector<Node*> lists){
    Node* head = lists[0];
    for(int i = 1;i<lists.size();i++){
        head = mergeTwoLL(head,lists[i]);
    }
    return head;
}

int main(){
    vector<vector<int>> arr = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };
    vector<Node*> lists;
    for (auto it: arr) {
        lists.push_back(arrayToLL(it));
    }
    //Node* merged = mergeLL(lists);
    Node* merged = mergeLLBetter(lists);
    cout << "Merged List: ";
    traversalLL(merged);
}