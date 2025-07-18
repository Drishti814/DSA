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

Node* buildTree(vector<int> &postorder,int postStart,int postEnd,vector<int> &inorder,int inStart,int inEnd, map<int,int> &mpp){
    if(postStart>postEnd || inStart>inEnd) return NULL;
    Node* root = new Node(postorder[postEnd]);
    int inRoot = mpp[root->data];
    int numsLeft = inRoot-inStart;
    root->left = buildTree(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inRoot-1,mpp);
    root->right = buildTree(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,mpp);
    return root;
}

//optimal
//TC O(n)
//SC O(n) for map + O(H) auxillary stack space ~ O(n)
Node* constructTree(vector<int> &postorder,vector<int> &inorder){
    map<int, int> mpp;
    for(int i = 0;i<inorder.size();i++){
        mpp[inorder[i]] = i;
    }

    Node* root = buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
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
    vector<int> postorder = {40,50,20,60,30,10};
    Node* root = constructTree(postorder,inorder);
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
