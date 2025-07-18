#include<iostream>
#include<vector>
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

Node* buildTree(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd, map<int,int> &mpp){
    if(preStart>preEnd || inStart>inEnd) return NULL;
    Node* root = new Node(preorder[preStart]);
    int indRoot = mpp[root->data];
    int numsLeft = indRoot-inStart;
    root->left = buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,indRoot-1,mpp);
    root->right = buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,indRoot+1,inEnd,mpp);
    return root;
}

//optimal
//TC O(n)
//SC O(n) for map + O(H) auxillary stack space ~ O(n)
Node* constructTree(vector<int> &preorder,vector<int> &inorder){
    map<int, int> mpp;
    for(int i = 0;i<inorder.size();i++){
        mpp[inorder[i]] = i;
    }

    Node* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;

}

void inOrder(Node* root){
    if(root==nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main(){
    vector<int> inorder = {40,20,50,10,60,30};
    vector<int> preorder = {10,20,40,50,30,60};
    Node* root = constructTree(preorder,inorder);
    inOrder(root);
}

//result-
//          10
//         /   \
//        /     \
//       20     30
//      / \     / 
//     /   \   /    
//    40   50 60    
