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

bool isLeaf(Node* node){
    if(node->left == nullptr && node->right==nullptr) return true;
    return false;
}

void leftBoundary(Node* node, vector<int> &ans){
    Node* curr = node->left;
    while(curr!=nullptr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left!=nullptr) curr = curr->left;
        else curr = curr->right;
    }
}

void leafBoundary(Node* node, vector<int> &ans){
    Node* curr = node;
    if(isLeaf(curr)){
        ans.push_back(curr->data);
        return;
    } 
    if(curr->left!=nullptr) leafBoundary(curr->left,ans);
    if(curr->right!=nullptr) leafBoundary(curr->right,ans);
}

void rightBoundary(Node* node, vector<int> &ans){
    Node* curr = node->right;
    vector<int> temp;
    while (curr!=nullptr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right!=nullptr) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

//optimal
//TC O(n)+O(n)+O(n)~O(n) (traversal + left boundary + right boundary)
//SC O(n) for temp + O(n) to print result(not extra space)
vector<int> boundaryTraversal(Node* root){
    if(root==nullptr) return {};
    vector<int> ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    leftBoundary(root,ans);
    leafBoundary(root,ans);
    rightBoundary(root,ans);
    return ans;
}

void printResult(const vector<int> &result){
    for(auto it : result){
        cout << it << " ";
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> result = boundaryTraversal(root);
    printResult(result);
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     / \
//   /   \   /   \ 
//  4     5 6     7
// boundary - 1 2 4 5 6 7 3