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
//TC O(logn)
//SC O(1)
int ceilBST(Node* root, int val){
    int ceil = -1;
    if(root==nullptr) return -1;
    while(root){
        if(root->data==val){
        ceil = root->data;
        return ceil;
        } 
        else if(root->data>val){
            ceil = root->data;
            root = root->left;
        } 
        else{
            root = root->right;
        } 
    }
    return ceil;
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
    int val = 11;
    int ceil = ceilBST(root,val);
    cout << ceil;
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
// ceil of 11 = 12