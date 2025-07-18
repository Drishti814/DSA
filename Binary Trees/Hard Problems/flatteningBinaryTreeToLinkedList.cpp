#include<iostream>
#include<vector>
#include<stack>
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

class Solution{
public : 
    //brute force
    //TC O(n)
    //SC O(n)
    Node* prev = NULL;
    void flattenBT(Node* root){
        if(root == nullptr) return;
        flattenBT(root->right);
        flattenBT(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }

    //better
    //TC O(n)
    //SC O(n)
    void flattenBTBetter(Node* root){
        if(root==nullptr) return;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            if(curr->right){
                st.push(curr->right);
            }if(curr->left){
                st.push(curr->left);
            }
            if(!st.empty()){
                curr->right = st.top();
                curr->left = NULL;
            }
        }
    }

    //optimal
    //TC O(2n)
    //SC O(1)
    void flattenBTOptimal(Node* root){
        Node* curr = root;
        while(curr!=nullptr){
            if(curr->left!=nullptr){
                Node* previous = curr->left;
                while(previous->right){
                    previous = previous->right;
                }
                previous->right = curr->right;
                curr->right = curr->left; 
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

void preorder(Node* root, vector<int> &arr){
    if(root == nullptr) return;
    arr.push_back(root->data);
    preorder(root->left,arr);
    preorder(root->right,arr);
}

void printFlattenBT(Node* root){
    if(root==nullptr) return;
    cout << root->data << " ";
    printFlattenBT(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    vector<int> arr;
    preorder(root,arr);
    for(auto it : arr){
        cout << it << " ";
    }
    Solution sol;
    //sol.flattenBT(root);
    //sol.flattenBTBetter(root);
    sol.flattenBTOptimal(root);
    cout << endl;
    printFlattenBT(root);
}

//         1
//       /   \
//      /     \
//     2       5
//    / \       \
//   /   \       \ 
//  3     4       6
//               /
//              /
//             7
// inorder - 4 2 5 1 6 3 7