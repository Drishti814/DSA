#include<iostream>
#include<vector>
#include<climits>
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

void inorder(Node* root, vector<int> &arr){
    if(root == nullptr) return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

//brute force
//TC O(n)
//SC O(n)
pair<int,int> findKth(Node* root, int k){
    vector<int> arr;
    inorder(root,arr);
    int n = arr.size();
    int kSmallest =  arr[k - 1];
    int kLargest = arr[n-k];
    return make_pair(kSmallest,kLargest);
}

//optimal
//TC O(n)
//SC O(1)
int kthSmallest(Node* root, int k){
    int cnt = 0;
    Node* curr = root;
    while(curr!=nullptr){
        if(!curr->left){
            cnt++;
            if(cnt == k) return curr->data;
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == curr){
                prev->right = NULL;
                cnt++;
                if(cnt == k) return curr->data;
                curr = curr->right;
            }
            else{
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
    return -1;
}

int kthLargest(Node* root, int k){
    int cnt = 0;
    Node* curr = root;
    while(curr!=nullptr){
        if(!curr->right){
            cnt++;
            if(cnt == k) return curr->data;
            curr = curr->left;
        }
        else{
            Node* prev = curr->right;
            while(prev->left && prev->left != curr){
                prev = prev->left;
            }
            if(prev->left == curr){
                prev->left = NULL;
                cnt++;
                if(cnt == k) return curr->data;
                curr = curr->left;
            }
            else{
                prev->left = curr;
                curr = curr->right;
            }
        }
    }
    return -1;
}

pair<int,int> findKthOptimal(Node* root, int k){
    int kSmallest =kthSmallest(root,k);
    int kLargest = kthLargest(root,k);
    return make_pair(kSmallest,kLargest);
}

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
    int k = 3;
    //pair<int,int> ans = findKth(root,k);
    pair<int,int> ans = findKthOptimal(root,k);
    cout << ans.first << " " << ans.second;
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
// 3rd smallest - 6
// 3rd largest - 12