#include<iostream>
#include<vector>
#include<climits>
#include<stack>
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

//brute force - validate bst then using another func to count nodes
//TC O(n^2)

//optimal
//TC O(n)
//SC O(1)
class NodeValue{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int maxNode, int minNode, int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class Solution{
private:
    NodeValue largestBSThelper(Node* root){
        if(!root) return NodeValue(INT_MIN,INT_MAX,0);
        auto left = largestBSThelper(root->left);
        auto right = largestBSThelper(root->right);
        if(left.maxNode < root->data && root->data < right.minNode){
            return NodeValue(max(root->data,right.maxNode),min(root->data,left.minNode),left.maxSize+right.maxSize+1);
        }
            return NodeValue(INT_MAX,INT_MIN,max(left.maxSize,right.maxSize));
    }
public:
    int largestBST(Node* root){
        return largestBSThelper(root).maxSize;
    }
};

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);
    Solution sol;
    int ans = sol.largestBST(root);
    cout << ans;
}

//         10
//       /   \
//      /     \
//     5       15
//    / \        \
//   /   \        \ 
//  1     8        7
