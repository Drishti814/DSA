#include<iostream>
#include<vector>
#include<math.h>
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

void inorder(Node* root, int &cnt){
    if(root == nullptr) return;
    inorder(root->left,cnt);
    cnt++; 
    inorder(root->right,cnt);
}

//brute force
//TC O(n)
//SC O(H)~O(logn)
int countNodes(Node* root){
    if(root==nullptr) return 0;
    int cnt = 0;
    inorder(root,cnt);
    return cnt;
}

int heightLeft(Node* root){
    int h = 0;
    while(root){
        h++;
        root = root->left;
    }
    return h;
}

int heightRight(Node* root){
    int h = 0;
    while(root){
        h++;
        root = root->right;
    }
    return h;
}

//optimal
//TC O(logn)^2
//SC O(H)~O(logn)
int countNodesOptimal(Node* root){
    if(root==nullptr) return 0;
    int left = heightLeft(root);
    int right = heightRight(root);
    if(left==right) return (1<<left) - 1;
    return countNodesOptimal(root->left) + countNodesOptimal(root->right) + 1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    //int total = countNodes(root);
    int total = countNodesOptimal(root);
    cout << total;
}

//           1
//         /   \
//        /     \
//       2       3
//      / \     / \
//     /   \   /   \ 
//    4     5 6     7
//   / \   / \
//  /   \ /   \
// 8    9 10   11
// total nodes - 7