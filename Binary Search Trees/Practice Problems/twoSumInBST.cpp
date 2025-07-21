#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//brute force - store inorder in stack
//TC O(1)
//SC O(n)

//optimal
//TC O(1)
//SC O(H)
class BSTIterator {
private: 
    stack<Node*> st;
    //reverse = true implies before
    //reverse = false implies next
    bool reverse = false;
public:
    BSTIterator(Node* root,bool isReverse){ 
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        Node* temp = st.top();
        st.pop();
        if(reverse==false) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->data;
    }

    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(Node* root){
        //both are same
        //for(;root!=nullptr;st.push(root),root = root->left);
        while(root){
            st.push(root);
            if(reverse==false) root = root->left;
            else root = root->right;
        }
    }
};

class Solution{
public: 
    bool TwoSum(Node* root, int target){
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next();   //j = r.before();
        while(i<j){
            if(i+j == target) return true;
            else if(i+j < target) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    int target = 16;
    Solution sol;
    bool found = sol.TwoSum(root,target);
    cout << found;
}

//         8
//       /   \
//      /     \
//     5       12
//    / \      / \
//   /   \    /   \ 
//  4     7  10    14
//       /        /
//      /        /
//     6       13
//target 16 = true