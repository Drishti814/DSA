#include<iostream>
#include<vector>
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

//successor - first value greater than given key
//predecessor - first value smaller than given key

//brute force - store inorder and traverse to find successor
//TC O(n)
//SC O(n)

//better - morris inorder and traverse to find successor
//TC O(n)
//SC O(1)

//optimal
//TC O(H)
//SC O(1)
Node* inorderSuccessor(Node* root, Node* key){
    Node* succ = NULL;
    if(root==nullptr) return NULL;
    while(root != nullptr){
        if(root->data <= key->data) root= root->right;
        else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* key){
    Node* pred = NULL;
    if(root==nullptr) return NULL;
    while(root != nullptr){
        if(root->data >= key->data) root= root->left;
        else{
            pred = root;
            root = root->right;
        }
    }
    return pred;
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
    Node* key = root->right->left;
    Node* succ = inorderSuccessor(root,key);
    cout << succ->data << " ";
    Node* pred = inorderPredecessor(root,key);
    cout << pred->data;
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
// succ of 10 - 12
// pred of 10 - 8