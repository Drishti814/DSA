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

//brute force - store inorder in stack
//TC O(1)
//SC O(n)

//optimal
//TC O(1)
//SC O(H)
class BSTIterator {
private: 
    stack<Node*> st;
public:
    BSTIterator(Node* root){ 
        pushAll(root);
    }
    
    int next() {
        Node* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    int before() {
        Node* temp = st.top();
        st.pop();
        pushAllRight(temp->left);
        return temp->data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(Node* root){
        //both are same
        //for(;root!=nullptr;st.push(root),root = root->left);
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    void pushAllRight(Node* root){
        //both are same
        //for(;root!=nullptr;st.push(root),root = root->left);
        while(root){
            st.push(root);
            root = root->right;
        }
    }
};

class BSTIteratorBefore {
private: 
    stack<Node*> st;
public:
    BSTIteratorBefore(Node* root){ 
        pushAll(root);
    }

    int before() {
        Node* temp = st.top();
        st.pop();
        pushAll(temp->left);
        return temp->data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(Node* root){
        //for(;root!=nullptr;st.push(root),root = root->right);
        while(root){
            st.push(root);
            root = root->right;
        }
    }
};

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    BSTIterator it(root);
    while(it.hasNext()==true){
        cout << it.next() << " ";
    }
    cout << endl;
    BSTIteratorBefore itB(root);
    while(itB.hasNext()==true){
        cout << itB.before() << " ";
    }
}

//         8
//       /   \
//      /     \
//     5       12
//    / \      / \
//   /   \    /   \ 
//  4     7  10    14
//       /        /
//      /        /
//     6       13