#include<iostream>
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

//same as bottom one
Node* searchBST(Node* root, int val){
    if(root==nullptr) return NULL;
    if(root->data==val) return root;
    else if(root->data>val) return searchBST(root->left,val);
    else return searchBST(root->right,val);
}

//optimal
//TC O(log2n)
//SC O(1) worst case - O(H)
Node* searchBinarySearchTree(Node* root, int val){
    while(root!=nullptr && root->data!=val){
        root = root->data > val ? root->left : root->right;
    }
    return root;
}

void preorder(Node* node){
    if(node==nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
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
    int val = 12;
    //Node* ans = searchBST(root,val);
    Node* ans = searchBinarySearchTree(root,val);
    preorder(ans);
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
// preorder if 12 exists - 12 10 14 13