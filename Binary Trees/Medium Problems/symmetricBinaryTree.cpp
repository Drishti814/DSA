#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

bool isSymmetricCheck(Node* left, Node* right){
    if(left==nullptr || right==nullptr) return left==right;
    if(left->data!=right->data) return false;
    if(isSymmetricCheck(left->left,right->right) && 
    isSymmetricCheck(left->right,right->left)==true) return true;
    return false;
}

//optimal
//TC O(n)
//SC O(1) worst case - O(H)
bool isSymmetric(Node* root){
    if(root==nullptr) return true;
    if(isSymmetricCheck(root->left,root->right)==true) return true;
    return false;

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
    root->left->right->left = new Node(5);
    root->right->left->right = new Node(5);
    bool ans = isSymmetric(root);
    cout << ans;
}

//         1
//       /   \
//      /     \
//     2       2
//    / \     / \
//   /   \   /   \ 
//  4     3 3     4
//       /   \
//      /     \
//     5       5
// symmetric - yes