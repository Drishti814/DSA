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

//optimal
//TC O(H)
//SC O(1)
Node* LCAofBST(Node* root, Node* x, Node* y){
    if(root==nullptr) return NULL;

    if(root->data < x->data && root->data < y->data){
        return LCAofBST(root->right,x,y);
    }
    if(root->data > x->data && root->data > y->data){
        return LCAofBST(root->left,x,y);
    }
    return root;
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
    Node* x = root->left->left;
    Node* y = root->left->right->left;
    Node* LCA = LCAofBST(root,x,y);
    cout << LCA->data;
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
// LCA(4,6) - 5