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

bool indenticalTrees(Node* p, Node* q){
    if(p==nullptr || q==nullptr) return (p==q);
    if(p->data==q->data && indenticalTrees(p->left,q->left) && indenticalTrees(p->right,q->right)){
        return true;
    }
    return false;
}

int main(){
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);
    p->left->left = new Node(4);
    p->left->right = new Node(5);
    p->right->left = new Node(6);
    p->right->right = new Node(7);
    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);
    q->left->left = new Node(4);
    q->left->right = new Node(5);
    q->right->left = new Node(6);
    q->right->right = new Node(7);
    bool ans = indenticalTrees(p,q);
    cout << ans;
}

