#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

class LRUCache {
    public:
        class Node{ 
        public: 
            int key;
            int val;
            Node* next;
            Node* back;

            public:
            Node(int key1, int val1, Node* next1, Node* back1){
                key = key1;
                val = val1;
                next = next1;
                back = back1;
            }

            public: 
            Node(int key1, int val1){
                key = key1;
                val = val1;
                next = back = nullptr;
            }
        };

   
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mpp;
    int Capacity;

    //O(1)
    LRUCache(int capacity) {
        Capacity = capacity;
        mpp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->back = head;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->back;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->back = prevNode;

    }

    void insertAtFront(Node* node){
        Node* curr = head->next;
        head->next = node;
        node->next = curr; 
        node->back = head;
        curr->back = node;
    }
    
    //O(1)
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1; 
        Node* node = mpp[key];
        deleteNode(node);
        insertAtFront(node);
        return node->val;
    }
    
    //O(1)
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAtFront(node);
        }
        else{
            if(mpp.size()==Capacity){
                Node* node = tail->back;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* newNode = new Node(key,value);
            mpp[key] = newNode;
            insertAtFront(newNode);
        }
    }
};

int main(){
    LRUCache cache(2); // capacity = 2

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; // 10

    cache.put(3, 30); // removes key=2

    cout << cache.get(2) << endl; // -1 (not found)
    cout << cache.get(3) << endl; // 30

    cache.put(4, 40); // removes key=1

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 30
    cout << cache.get(4) << endl; // 40
}