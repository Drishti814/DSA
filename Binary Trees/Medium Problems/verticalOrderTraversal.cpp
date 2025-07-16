#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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

vector<vector<int>> verticalTraversal(Node* root){
    queue<pair<Node*,pair<int,int>>> q;
    map<int,map<int,multiset<int>>> mpp;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto el = q.front();
        q.pop();
        Node* node = el.first;
        int x = el.second.first;
        int y = el.second.second;
        mpp[x][y].insert(node->data);
        if(node->left!=nullptr){
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right!=nullptr){
            q.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto it: mpp){
        vector<int> values;
        for(auto val: it.second){
            values.insert(values.end(),val.second.begin(),val.second.end());
        }
        ans.push_back(values);
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
    vector<vector<int>> ans = verticalTraversal(root);
    for(auto it:ans){
        for(auto el:it){
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
// vertical - 4 2 1 5 6 3 7