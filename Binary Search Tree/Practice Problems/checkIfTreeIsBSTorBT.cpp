#include<iostream>
#include<climits>
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

bool isValidBST(Node* root, long long left, long long right){
    if(root==nullptr) return true;
    if(left >= root->data || root->data >= right) return false;
    return isValidBST(root->left,left, root->data) &&
    isValidBST(root->right,root->data,right);
}

bool validateBST(Node* root){
    return isValidBST(root,LLONG_MIN,LLONG_MAX);
}

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
    bool valid = validateBST(root);
    cout << valid ;
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
// valid