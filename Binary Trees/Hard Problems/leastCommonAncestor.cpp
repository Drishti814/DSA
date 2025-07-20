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

bool rootToNodePathExist(Node* root,vector<int> &path, int target){
    if(root==nullptr) return false;
    path.push_back(root->data);
    if(root->data==target){
        return true;
    }
    if(rootToNodePathExist(root->left,path,target)||rootToNodePathExist(root->right,path,target)) return true;
    path.pop_back();
    return false;
}

vector<int> rootToNodePath(Node* root,int target){
    vector<int> path;
    if(root==nullptr) return path;
    rootToNodePathExist(root,path,target);
    return path;
}

//brute force
//TC O(n)
//SC O(2n)
int LCA(Node* root, int t1, int t2){
    vector<int> p1 = rootToNodePath(root,t1);
    vector<int> p2 = rootToNodePath(root,t2);
    int i = 0;
    while(i<p1.size()&&i<p2.size() && p1[i]==p2[i]){
        i++;
    }
    return p1[i-1];
}

//optimal
//TC O(n)
//SC O(n)
Node* LCAOptimal(Node* root, Node* p, Node* q){
    if(root==nullptr||root==p||root==q) return root;
    Node* left = LCAOptimal(root->left,p,q);
    Node* right = LCAOptimal(root->right,p,q);
    if(left==nullptr){
        return right;
    }
    else if(right==nullptr){
        return left;
    }
    else return root;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    // int t1 = 4, t2 = 7;
    // int ans = LCA(root,t1,t2);
    // cout << ans;
    Node* ans = LCAOptimal(root,root->left->left,root->left->right->right);
    cout << ans->data;
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     
//   /   \   
//  4     5 
//       / \  
//      /   \   
//     6     7
// LCA(4,7) - 2