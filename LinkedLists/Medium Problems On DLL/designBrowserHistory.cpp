#include<iostream>
#include<vector>
using namespace std;

class Node{ 
    public: 
    string data;
    Node* next;
    Node* back;

    public:
    Node(string data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public: 
    Node(string data1){
        data = data1;
        next = back = nullptr;
    }
};

//SC O(N)
class BrowserHistory {
public:
    Node* curr = nullptr;

    //TC O(1)
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    //TC O(1)
    void visit(string url) {
        curr->next = nullptr;
        Node* newPage = new Node(url);
        curr->next = newPage;
        newPage->back = curr;
        curr = newPage;
    }
    
    //TC O(steps)
    string back(int steps) {
        while(steps){
            if(curr->back) curr = curr->back;
            else break;
            steps--;
        }
        return curr->data;
    }
    
    //TC O(steps)
    string forward(int steps) {
        while(steps){
            if(curr->next) curr = curr->next;
            else break;
            steps--;
        }
        return curr->data;
    }
};

int main(){
    BrowserHistory* browser = new BrowserHistory("a.com");
    cout << "Start at: " << browser->back(0) << endl; // a.com
    browser->visit("b.com");
    browser->visit("c.com");
    cout << "After visiting b and c: " << browser->back(0) << endl; // c.com
    cout << "Back 1: " << browser->back(1) << endl;   // b.com
    cout << "Back 1 more: " << browser->back(1) << endl; // a.com
    cout << "Forward 1: " << browser->forward(1) << endl; // b.com
    browser->visit("d.com"); // This should delete forward history (c.com)
    cout << "Current page after visiting d: " << browser->back(0) << endl; // d.com
    cout << "Try forward 1 (should do nothing): " << browser->forward(1) << endl; // d.com
    cout << "Back 2: " << browser->back(2) << endl; // a.com
    cout << "Forward 3: " << browser->forward(3) << endl; // d.com
}