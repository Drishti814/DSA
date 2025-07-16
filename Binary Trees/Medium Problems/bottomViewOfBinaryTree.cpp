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

//we can't use recursive traversal
//optimal
//TC O(n)
//SC O(n)
vector<int> verticalTraversal(Node* root){
    if(root==nullptr) return {};
    queue<pair<Node*,int>> q;
    map<int,int> mpp;
    q.push({root,0});
    while(!q.empty()){
        auto el = q.front();
        q.pop();
        Node* node = el.first;
        int x = el.second;
        mpp[x]=(node->data);
        if(node->left!=nullptr){
            q.push({node->left,x-1});
        }
        if(node->right!=nullptr){
            q.push({node->right,x+1});
        }
    }
    vector<int> ans;
    for(auto it: mpp){
       ans.push_back(it.second);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->left->right = new Node(9);
    vector<int> ans = verticalTraversal(root);
    for(auto it:ans){
        cout << it << " ";
    }
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     / \
//   /   \   /   \ 
//  4     5 6     7
//       /   \
//      /     \
//     8       9
// bottom view - 4 8 6 9 7