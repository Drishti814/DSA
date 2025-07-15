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

//optimal
//TC O(3n)
//SC O(4n) for stack ~ O(H) H=height of BT
vector<vector<int>> preInPostorder(Node* root){
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    stack<pair<Node*,int>> st;
    st.push({root,1});
    if(root==nullptr) return {};
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != nullptr){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != nullptr){
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    vector<vector<int>> ans =  preInPostorder(root);
    for(auto it: ans){
        for(auto el : it){
            cout << el << " ";
        }
        cout << endl;
    }
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     / \
//   /   \   /   \ 
//  4     5 6     7
// preorder - 1 2 4 5 3 6 7 
// inorder - 4 2 5 1 6 3 7
// postorder - 4 5 2 6 7 3 1