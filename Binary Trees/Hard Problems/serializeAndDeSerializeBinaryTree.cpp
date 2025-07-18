#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
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
//SC O(n)
string serialize(Node* root){
    if(root==nullptr) return "";
    string s = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node==nullptr) s.append("#,");
        else s.append(to_string(node->data)+',');
        if(node){
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

//optimal
//TC O(n)
//SC O(n)
Node* deSerialize(string data){
    if(data.empty()) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            node->left = NULL;
        }
        else{
            Node* leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#"){
            node->right = NULL;
        }
        else{
            Node* rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void inOrder(Node* root){
    if(root==nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    string s = serialize(root);
    cout << s << endl;
    Node* node = deSerialize(s);
    inOrder(node);
}

//         1
//       /   \
//      /     \
//     2       3
//    / \     / \
//   /   \   /   \ 
// NULL NULL 6    7
// string - 1,2,3,#,#,6,7,#,#,#,#
//root - 1