#include<iostream>
#include<vector>
#include<queue>
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
//SC O(H)
void ChildrenSumProperty(Node* root){
    if(root==nullptr) return;
    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }
    if(child >= root->data){
        root->data = child;
    }  
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    ChildrenSumProperty(root->left);
    ChildrenSumProperty(root->right);

    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total;
}

void preorderTraversal(Node* root){
    if(root==nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);
    ChildrenSumProperty(root);
    preorderTraversal(root);
}

//         50
//       /   \
//      /     \
//     7       2
//    / \     / \
//   /   \   /   \ 
//  3     5 1     30
//  output - 
//        200
//       /   \
//      /     \
//    100     100
//    / \     / \
//   /   \   /   \ 
//  50   50 50    50