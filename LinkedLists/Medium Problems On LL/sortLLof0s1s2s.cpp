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
//TC O(N)
//SC O(N)
Node* sort0s1s2s(Node* head){
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
//TC O(N/2)
//SC O(1)
Node* oddEvenOptimal(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* odd = head;
    Node* evenHead = head->next;
     Node* even = head->next;
    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(){
    vector<int> arr1 = {1,0,1,2,0,2,1};
    Node* head1 = arrayToLL(arr1);
    cout << "before: ";
    traversalLL(head1);
    cout << endl;
    cout << "after: ";   
    Node* ans = sort0s1s2s(head1);
    //Node* ans = oddEvenOptimal(head1);
    traversalLL(ans);
}