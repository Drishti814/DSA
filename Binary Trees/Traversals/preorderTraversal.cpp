#include<iostream>
#include<vector>
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

void preorder(Node* root, vector<int> &arr){
    if(root == nullptr) return;
    arr.push_back(root->data);
    preorder(root->left,arr);
    preorder(root->right,arr);
}

//optimal
//TC O(n)
//SC O(n)
vector<int> preOrder(Node* root){
    vector<int> arr;
    preorder(root,arr);
    return arr;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> result = preOrder(root);
    for(auto it : result){
        cout << it << " ";
    }
}

//         1
//        /  \
//       /    \
//      2      3
//     / \    / \
//    /   \  /   \ 
//   4     56     7
// preorder - 1 2 4 5 3 6 7