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

void postorder(Node* root, vector<int> &arr){
    if(root == nullptr) return;
    postorder(root->left,arr);
    postorder(root->right,arr);
    arr.push_back(root->data);
}

//optimal
//TC O(n)
//SC O(n)
vector<int> postOrder(Node* root){
    vector<int> arr;
    postorder(root,arr);
    return arr;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> result = postOrder(root);
    for(auto it : result){
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
// postorder - 4 5 2 6 7 3 1