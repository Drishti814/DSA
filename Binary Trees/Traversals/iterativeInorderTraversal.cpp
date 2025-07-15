#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

//optimal
//TC O(n)
//SC O(n) for stack ~ O(H) H=height of BT
vector<int> inorderIterative(Node* root){
    vector<int> ans;
    if(root==nullptr) return ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        if(root->left!=nullptr) st.push(root->left);
        ans.push_back(root->data);
        st.pop();
        if(root->right!=nullptr) st.push(root->right);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = inorderIterative(root);
    for(auto it : ans){
            cout << it << " ";
    }
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     / \
//   /   \   /   \ 
//  4     5 6     7
// levelorder - 1 2 4 5 3 6 7