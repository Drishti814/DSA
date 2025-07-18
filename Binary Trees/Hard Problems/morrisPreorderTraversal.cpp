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

//optimal
//TC O(n)
//SC O(1)
vector<int> preOrder(Node* root){
    vector<int>preorder;
    if(root==nullptr) return preorder;
    Node* curr = root;
    while(curr!=nullptr){
        if(!curr->left){
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == curr){
                prev->right = NULL;
                curr = curr->right;
            }
            else{
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
        }
    }
    return preorder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    vector<int> result = preOrder(root);
    for(auto it : result){
        cout << it << " ";
    }
}

//         1
//       /   \
//      /     \
//     2       3
//    / \       
//   /   \      
//  4     5     
//         \
//          \
//           6
// preorder - 1 2 4 5 6 3