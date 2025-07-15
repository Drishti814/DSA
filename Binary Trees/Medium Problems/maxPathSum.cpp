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
        left = right = nullptr;
    }
};

int dfsHeight(Node* root, int &maxi){
    if(root==nullptr) return 0;
    int left = max(0,dfsHeight(root->left,maxi));
    int right = max(0,dfsHeight(root->right,maxi));
    maxi = max(maxi,left+right+root->data);
    return root->data + max(left,right);
}

//optimal
//TC O(n)
//SC O(1)
int maxPathSum(Node* node){
    int maxi = INT_MIN;
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
    
    int ans = maxPathSum(root);
    cout << ans;
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     / \
//   /   \   /   \ 
//  4     5 6     7
// max path sum - 18
