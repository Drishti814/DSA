#include<iostream>
#include<vector>
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

Node* findTail(Node* head){
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    return tail;
}

//brute force
//TC O(N^2)
//SC O(1)
vector<pair<int,int>> PairSum(Node* head, int sum){
    vector<pair<int,int>> pairs;
    Node* temp1 = head;
    while(temp1){
        Node* temp2 = temp1->next;
        while(temp2 && (temp1->data+temp2->data <= sum)){
            if(temp1->data + temp2->data == sum) pairs.push_back({temp1->data,temp2->data});
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
   return pairs;
}

//Optimal
//TC O(N)
//SC O(1)
vector<pair<int,int>> PairSumOptimal(Node* head, int sum){
    Node* tail = findTail(head);
    vector<pair<int,int>> pairs;
    if(head==nullptr) return pairs;
    Node* left = head;
    Node* right = tail;
    while(left->data < right->data){
        if(left->data+right->data==sum){
            pairs.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data+right->data < sum) left = left->next;
        else right = right->back;
   }
   return pairs;
}

int main(){
    vector<int> arr = {1,2,3,4,9};
    Node* head = arrayToDLL(arr);
    cout << "LL: ";
    traversalDLL(head);
    cout  << endl;
    cout << "Pairs with sum 5: ";
    vector<pair<int,int>> ans = PairSumOptimal(head,5);
    //vector<pair<int,int>> ans = PairSumOptimal(head,5);
    cout  << endl;
    for(auto it : ans){
        cout << it.first << "," << it.second << endl;
    }
}