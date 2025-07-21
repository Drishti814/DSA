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

//swap 2 incorrectly placed elements i.e. recover BST

//brute force - store inorder then sort it then use that to make changes
//TC O(2n+nlogn)
//SC O(n)

//optimal
//TC O(n)
//SC O(1)
class Solution{
private: 
    Node* first;
    Node* prev;
    Node* middle;
    Node* last;
private:
    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        if(prev!=nullptr && root->data < prev->data){
            if(first==nullptr){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
public: 
    void recoverBST(Node* root){
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorder(root);
        if(first && last) swap(first->data,last->data);
        else if(first && middle) swap(first->data,middle->data);
    }
    void printInorder(Node* root){
        if(!root) return;
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
};

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(10);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    Solution sol;
    sol.printInorder(root);
    cout << endl;
    sol.recoverBST(root);
    sol.printInorder(root);
}

//         8
//       /   \
//      /     \
//     5       12
//    / \      / \
//   /   \    /   \ 
//  4     7  6    14
//       /        /
//      /        /
//    10       13
// output - 
//         8
//       /   \
//      /     \
//     5       12
//    / \      / \
//   /   \    /   \ 
//  4     7 10    14
//       /        /
//      /        /
//     6       13