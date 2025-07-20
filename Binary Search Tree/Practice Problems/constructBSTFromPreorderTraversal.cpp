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

//brute force - traversing preorder and checking all nodes position left or right
//TC O(n^2)
//SC O(n)

//better - sort preorder(becomes inorder) and using both construct BT(BST in this case)
//TC O(nlogn)+O(n)
//SC O(n)

Node* preorderBST(vector<int> &preorder,int &n, long long upperLimit){
    if(n == preorder.size() || preorder[n]>upperLimit) return NULL;
    Node* root = new Node(preorder[n++]);
    root->left = preorderBST(preorder,n,root->data);
    root->right = preorderBST(preorder,n,upperLimit);
    return root;
}

//optimal
//TC O(n)
//SC O(1)
Node* BSTfromPreorder(vector<int> &preorder){
    int n = 0;
    return(preorderBST(preorder,n,LLONG_MAX));
}

void printPreorder(Node* root){
    if(root==nullptr) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    vector<int> preorder = {8,5,4,7,6,12,10,14,13};
    Node* ans = BSTfromPreorder(preorder);
    printPreorder(ans);
}

// output - 
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