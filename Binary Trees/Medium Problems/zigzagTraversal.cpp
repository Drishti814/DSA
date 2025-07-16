#include<iostream>
#include<vector>
#include<queue>
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
//SC O(n) for queue + O(n) for result vector
vector<vector<int>> zigzagTraversal(Node* root){
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    queue<Node*> q;
    q.push(root);
    bool LtoR = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);
        for(int i = 0;i<size;i++){
            Node* node = q.front();
            q.pop();
            int index = (LtoR) ? i : (size - i - 1);
            level[index] = (node->data);
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
        }
        LtoR = !LtoR;
        ans.push_back(level);
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
    vector<vector<int>> ans = zigzagTraversal(root);
    for(auto it : ans){
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
// zigzag - 1 3 2 4 5 6 7