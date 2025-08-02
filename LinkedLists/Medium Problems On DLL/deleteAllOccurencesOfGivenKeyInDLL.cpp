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

//Optimal
//TC O(N)
//SC O(1)
Node* deleteKey(Node* head, int key){
    Node* temp = head;
    while(temp){
        if(temp->data==key){
            if(temp==head){
                head=head->next;
            }
            Node* prev = temp->back;
            Node* front = temp->next;
            if(prev) prev->next = front;
            if(front) front->back = prev;
            delete temp;
            temp = front;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,1,4,1,6,7,1};
    Node* head = arrayToDLL(arr);
    cout << "before: ";
    traversalDLL(head);
    cout  << endl;
    cout << "after: ";
    Node* ans = deleteKey(head,1);
    traversalDLL(ans);  
}