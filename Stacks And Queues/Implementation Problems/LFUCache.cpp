#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

class LFUCache {
    public:
        class Node{ 
            public: 
            int key;
            int val;
            Node* next;
            Node* back;
            int cnt;

            public:
            Node(int key1, int val1, Node* next1, Node* back1){
                key = key1;
                val = val1;
                next = next1;
                back = back1;
                cnt = 1;
            }

            public: 
            Node(int key1, int val1){
                key = key1;
                val = val1;
                next = back = nullptr;
                cnt = 1;
            }
        };

    public:
        class List{
            public:
            int size;
            Node* head;
            Node* tail;
            
            List(){
                size = 0;
                head = new Node(0,0);
                tail = new Node(0,0);
                head->next = tail;
                tail->back = head;
            }
            void insertAtFront(Node* node){
                Node* curr = head->next;
                head->next = node;
                node->next = curr; 
                node->back = head;
                curr->back = node;
                size++;
            }
            void deleteNode(Node* node){
                Node* prevNode = node->back;
                Node* nextNode = node->next;
                prevNode->next = nextNode;
                nextNode->back = prevNode;
                size--;
            }
        };   

    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqListMap;
    int Capacity;
    int minFreq;
    int currSize;

    //O(1)
    LFUCache(int capacity) {
        Capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherFreqList= freqListMap[node->cnt+1];
        }
        node->cnt++;
        nextHigherFreqList->insertAtFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key]= node;
    }

    //O(1)
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1; 
        Node* node = keyNode[key];
        updateFreqListMap(node);
        return node->val;
    }
    
    //O(1)
    void put(int key, int value) {
        if(Capacity==0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else{
            if(currSize == Capacity){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->back->key);
                freqListMap[minFreq]->deleteNode(list->tail->back);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node* newNode = new Node(key,value);
            listFreq->insertAtFront(newNode);
            keyNode[key] = newNode;
            freqListMap[minFreq] = listFreq;
        }
    }
};

int main(){
    cout << "Testing LFU Cache..." << endl;

    LFUCache lfu(2); // capacity = 2

    lfu.put(1, 10);  // cache = {1=10}
    lfu.put(2, 20);  // cache = {1=10, 2=20}
    cout << "get(1) -> " << lfu.get(1) << endl; // returns 10, freq(1)=2

    lfu.put(3, 30);  // evicts key=2 (freq=1), cache={1=10(freq2), 3=30}
    cout << "get(2) -> " << lfu.get(2) << endl; // returns -1
    cout << "get(3) -> " << lfu.get(3) << endl; // returns 30

    lfu.put(4, 40);  // evicts key=1 (freq=2 but oldest), cache={3=30, 4=40}
    cout << "get(1) -> " << lfu.get(1) << endl; // returns -1
    cout << "get(3) -> " << lfu.get(3) << endl; // returns 30
    cout << "get(4) -> " << lfu.get(4) << endl; // returns 40

    // more stress tests
    lfu.put(5, 50);  // evicts key=3 or 4 depending on freq
    cout << "get(3) -> " << lfu.get(3) << endl;
    cout << "get(4) -> " << lfu.get(4) << endl;
    cout << "get(5) -> " << lfu.get(5) << endl;

    lfu.put(6, 60);
    cout << "get(4) -> " << lfu.get(4) << endl;
    cout << "get(5) -> " << lfu.get(5) << endl;
    cout << "get(6) -> " << lfu.get(6) << endl;

    // random access to increase frequency
    cout << "get(5) -> " << lfu.get(5) << endl;
    cout << "get(5) -> " << lfu.get(5) << endl;
    cout << "get(6) -> " << lfu.get(6) << endl;

    lfu.put(7, 70); // this will evict LFU
    cout << "get(5) -> " << lfu.get(5) << endl;
    cout << "get(6) -> " << lfu.get(6) << endl;
    cout << "get(7) -> " << lfu.get(7) << endl;

    return 0;
}