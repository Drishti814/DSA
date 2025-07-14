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

void inorder(Node* root, vector<int> &arr){
    if(root == nullptr) return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

//optimal
//TC O(n)
//SC O(n)
vector<int> inOrder(Node* root){
    vector<int> arr;
    inorder(root,arr);
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
    vector<int> result = inOrder(root);
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
// inorder - 4 2 5 1 6 3 7