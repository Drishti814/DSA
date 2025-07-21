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
int floorBST(Node* root, int val){
    int floor = -1;
    if(root==nullptr) return -1;
    while(root){
        if(root->data==val){
        floor = root->data;
        return floor;
        } 
        else if(root->data>val){
            root = root->left;
        } 
        else{
            floor = root->data;
            root = root->right;
        } 
    }
    return floor;
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
    int floor = floorBST(root,val);
    cout << floor;
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
// floor of 11 = 10