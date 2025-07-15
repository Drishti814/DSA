#include<iostream>
#include<vector>
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

int heightBT(Node* root){
    if(root==nullptr) return 0;
    int left = heightBT(root->left);
    int right = heightBT(root->right);
    return 1 + max(left,right);
}

//brute force
//TC O(n^2)
//SC O(1) 
bool balancedBT(Node* node){
    if(node==nullptr) return true;
    int lh = heightBT(node->left);
    int rh = heightBT(node->right);;
    if(abs(lh - rh) > 1) return false;
    bool left = balancedBT(node->left);
    bool right = balancedBT(node->right);
    if (left == false || right == false) return false;
    return true;
}

int dfsheight(Node* root){
    if(root==nullptr) return 0;
    int left = dfsheight(root->left);
    int right = dfsheight(root->right);
    if (left == -1 || right == -1) return -1; //-1 is not balanced
    if(abs(left - right) > 1) return -1;
    return 1 + max(left,right); //height is balanced
}

//optimal
//TC O(n)
//SC O(1) 
bool isbalanced(Node* node){
    if(dfsheight(node) != -1) return true;
    return false;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    bool balanced = balancedBT(root);
    bool ans = isbalanced(root);
    cout << balanced << " ";
    cout << ans;
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     / \
//   /   \   /   \ 
//  4     5 6     7
// balanced - yes
