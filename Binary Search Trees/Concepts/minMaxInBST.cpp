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
//TC O(logn) balanced BST & O(n) for unbalanced
//SC O(1) as no extra space & O(H) recursive stack space

int minVal(Node* root){
    if(root==nullptr) return -1;
    while(root->left) {
        root = root->left;
    }
    return root->data;
}

int maxVal(Node* root){
    if(root==nullptr) return -1;
    while(root->right) {
        root = root->right;
    }
    return root->data;
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
    int min = minVal(root);
    cout << min << endl;
    int max = maxVal(root);
    cout << max << endl;
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
// min = 4, max = 14