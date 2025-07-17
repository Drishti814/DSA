#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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

void parent(Node* root, unordered_map<Node*, Node*> &parentTrack){
    if(root==nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left){
            parentTrack[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parentTrack[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

//optimal
//TC O(2n)
//SC O(3n)
int timeToBurn(Node* root, Node* target){
    unordered_map<Node*, Node*> parentTrack;
    parent(root,parentTrack);
    queue<Node*> q;
    q.push(target);
    unordered_map<Node*,bool> visited;
    visited[target] = true;
    int time = 0;
    while(!q.empty()){
        int size = q.size();
        bool burn = false;
        for(int i = 0;i<size;i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left] = true;
                burn = true;
            }
            if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right] = true;
                burn = true;
            }
            if(parentTrack[curr] && !visited[parentTrack[curr]]){
                q.push(parentTrack[curr]);
                visited[parentTrack[curr]] = true;
                burn = true;
            }
        }
        if(burn) time++;
    }
    return time;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    Node* target = root->left;
    int time = timeToBurn(root,target);
    cout << time;
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     / \
//   /   \   /   \ 
//  4     5 6     7
//       / \
//      /   \
//     8     9
// time - 3