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
//TC O(2n)
//SC O(n) for stack ~ O(H) H=height of BT
vector<int> postorderIterative(Node* root){
    vector<int> ans;
    if(root==nullptr) return ans;
    stack<Node*> st;
    Node* node = root;
    while(node!=nullptr || !st.empty()){
        if(node!=nullptr){
            st.push(node);
            node = node->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp==nullptr){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while((!st.empty() && temp == st.top()->right)){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                node = temp;
            }
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = postorderIterative(root);
    for(auto it : ans){
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