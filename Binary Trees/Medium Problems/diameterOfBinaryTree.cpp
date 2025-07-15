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
int maxD = 0;

int heightBT(Node* root){
    if(root==nullptr) return 0;
    int left = heightBT(root->left);
    int right = heightBT(root->right);
    maxD = max(maxD,left+right);
    return 1 + max(left,right);
}

//brute Force
//TC O(n^2)
//SC O(1)
int diameterBT(Node* node){
    heightBT(node);
    return maxD;
}

int dfsHeight(Node* root, int &maxi){
    if(root==nullptr) return 0;
    int left = dfsHeight(root->left,maxi);
    int right = dfsHeight(root->right,maxi);
    maxi = max(maxi,left+right);
    return 1 + max(left,right);
}

//optimal
//TC O(n)
//SC O(1)
int diameter(Node* node){
    int maxi = 0;
    dfsHeight(node,maxi);
    return maxi;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //int dia = diameterBT(root);
    int dia = diameter(root);
    cout << dia;
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     / \
//   /   \   /   \ 
//  4     5 6     7
// height - 3
