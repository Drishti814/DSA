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

vector<int> inOrder(Node* root){
    vector<int> inorder;
    if(root==nullptr) return inorder;
    Node* curr = root;
    while(curr!=nullptr){
        if(!curr->left){
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == curr){
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
    return inorder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    vector<int> result = inOrder(root);
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
// inorder - 4 2 5 1 6 3 7