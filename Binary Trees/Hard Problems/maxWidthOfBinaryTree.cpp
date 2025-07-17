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

//optimal
//TC O(n)
//SC O(n)
int maxWidth(Node* root){
    if(root==nullptr) return 0;
    int width = 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int minn = q.front().second;
        int first,last;
        for(int i = 0;i<size;i++){
            int curr = q.front().second - minn;
            Node* node = q.front().first;
            q.pop();
            if(i==0) first = curr;
            if(i==size-1) last = curr;
            if(node->left!=nullptr){
                q.push({node->left,2*curr + 1});
            }
            if(node->right!=nullptr){
                 q.push({node->right,2*curr + 2});
            }
        }
        width = max(width,last-first+1);
    }
    return width;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    int width = maxWidth(root);
    cout << width;
}

//         1
//       /   \
//      /     \
//     2       3
//    /         \     
//   /           \   
//  4             5 
// max width - 4