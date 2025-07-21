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

Node* insertNode(Node* root, int val){
    if(root==nullptr){
        return new Node(val);
    }
    Node* curr = root;
    while(true){
         if(curr->data > val){
            if(curr->left){
                curr = curr->left;
            }
            else{
                curr->left = new Node(val);
                break;
            } 
            
        }
        else{
            if(curr->right){
               curr = curr->right;
            }
            else{
                curr->right = new Node(val);
                break;
            }  
        }
    }
    return root;
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
    int val = 5;
    Node* ans = insertNode(root,val);
    preorder(ans);
}

//         4
//       /   \
//      /     \
//     2       7
//    / \      
//   /   \     
//  1     3  
// insert 5
// output - 
//         4
//       /   \
//      /     \
//     2       7
//    / \     /
//   /   \   / 
//  1     3 5 