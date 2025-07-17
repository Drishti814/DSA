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

bool rootToNodePathExist(Node* root,vector<int> &path, int target){
    if(root==nullptr) return false;
    path.push_back(root->data);
    if(root->data==target){
        return true;
    }
    if(rootToNodePathExist(root->left,path,target)||rootToNodePathExist(root->right,path,target)) return true;
    path.pop_back();
    return false;
}

//optimal
//TC O(n)
//SC O(H)
vector<int> rootToNodePath(Node* root,int target){
    vector<int> path;
    if(root==nullptr) return path;
    rootToNodePathExist(root,path,target);
    return path;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    int target = 7;
    vector<int> ans = rootToNodePath(root,target);
    for(auto it : ans){
        cout << it << " ";
    }
}