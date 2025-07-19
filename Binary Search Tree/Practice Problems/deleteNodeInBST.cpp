#include<iostream>
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

Node* findLastRight(Node* root){
    if(!root->right) return root;
    return findLastRight(root->right);
}

Node* helperFunc(Node* root){
    if(!root->left) return root->right;
    if(!root->right) return root->left;
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

//optimal
//TC O(logn)
//SC O(1)
Node* deleteNode(Node* root, int val){
    if(root==nullptr) return NULL;
    if(root->data == val){
        return helperFunc(root);
    }
    Node* dummy = root;
    while(root!=nullptr){
        if(root->data > val){
            if(root->left && root->left->data == val){
                root->left = helperFunc(root->left);
                break;
            }
            else root = root->left;

        }
        else{
            if(root->right && root->right->data == val){
                root->right = helperFunc(root->right);
                break;
            }
            else root = root->right;
        }
    }
    return dummy;
}

void preorder(Node* node){
    if(node==nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    int val = 2;
    Node* ans = deleteNode(root,val);
    preorder(ans);
}

//         4
//       /   \
//      /     \
//     2       7
//    / \      
//   /   \     
//  1     3  
// delete 2
// output - 
//         4
//       /   \
//      /     \
//     1       7
//      \     
//       \    
//        3  