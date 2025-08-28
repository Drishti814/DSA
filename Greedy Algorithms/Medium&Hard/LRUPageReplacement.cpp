#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

//brute force
//TC O(n * capacity)
//SC O(N+capacity)
void LRUPageReplacementBrute(vector<int>& pages, int capacity) {
    int n = pages.size();
    vector<int> frames;
    unordered_map<int,int> lastUsed;
    int faults = 0;
    for(int i = 0;i<n;i++){
        int page = pages[i];
        auto it = find(frames.begin(),frames.end(),page);
        if(it!=frames.end()){
            lastUsed[page] = i;
        }
        else{
            faults++;
            if(frames.size()<capacity){
                frames.push_back(page);
                lastUsed[page] = i;
            }
            else{
                int lruPage = frames[0];
                for(auto p:frames){
                    if(lastUsed[p]<lastUsed[lruPage]){
                        lruPage = p;
                    }
                }
                auto pos = find(frames.begin(), frames.end(), lruPage); 
                *pos = page; 
                lastUsed.erase(lruPage);   // erase entry for 2
                lastUsed[page] = i; 
            }
        }
        cout << "Step " << i+1 << " (page=" << page << "): ";
        for(int p : frames) cout << p << " ";
        cout << endl;
    }
    cout << "Total Page Faults = " << faults << endl;
}

//Belady’s Optimal Algorithm(optimal because it gives minimum page faults not computationally optimal)
//TC O(n^2 * capacity)
//SC O(capacity)
void LRUPageReplacement(vector<int>& pages, int capacity) {
    int n = pages.size();
    vector<int> frames;
    int faults = 0;
    for(int i = 0;i<n;i++){
        int page = pages[i];
        auto it = find(frames.begin(),frames.end(),page);
        if(it!=frames.end()){
        }
        else{
            faults++;
            if(frames.size()<capacity){
                frames.push_back(page);
            }
            else{
                int replaceIndex = -1;
                int farthest = i+1;
                for (int j = 0; j < frames.size(); j++) {
                    int k;
                    for(k = i+1;k<n;k++){
                        if(frames[j]==pages[k]){
                            break;
                        }
                    }
                    if(k==n){
                        replaceIndex = j;
                        break;
                    }
                    if(k>farthest){
                        replaceIndex = j;
                        farthest = k;
                    }
                }
                frames[replaceIndex] = page;
            }
        }
        cout << "Step " << i+1 << " (page=" << page << "): ";
        for(int p : frames) cout << p << " ";
        cout << endl;
    }
    cout << "Total Page Faults = " << faults << endl;
}

struct Frame{
    int page;
    int nextUse;
    bool operator< (const Frame &other) const{
        return nextUse<other.nextUse;
    }
};

//optimal
//TC O(N * log(capacity))
//SC O(N+capacity)
void LRUPageReplacementOptimal(vector<int>& pages, int capacity) {
    int n = pages.size();
    unordered_map<int,queue<int>> future;
    for(int i = 0;i<n;i++){
        future[pages[i]].push(i);
    }
    vector<int> frames;
    unordered_map<int, int> inFrame;    
    priority_queue<Frame> pq;  
    int faults = 0;

    for(int i = 0;i<n;i++){
        int page = pages[i];
        future[page].pop();

        int nextUse = (future[page].empty()?INT_MAX:future[page].front());

        if(inFrame.find(page) != inFrame.end()){
            inFrame[page] = nextUse;
            pq.push({page,nextUse});
        }
        else{
            faults++;
            if(frames.size()<capacity){
                frames.push_back(page);
                inFrame[page]=nextUse;
                pq.push({page,nextUse});
            }
            else{
                while(!pq.empty()){
                    Frame top = pq.top();
                    if(inFrame[top.page]!=top.nextUse){
                        pq.pop();
                    }
                    else break;
                }
            }
            Frame victim = pq.top(); 
            pq.pop();
            int evictPage = victim.page;
            for (int &f : frames) {
                if (f == evictPage) {
                    f = page;
                    break;
                }
            }
            inFrame.erase(evictPage);
            inFrame[page] = nextUse;
            pq.push({page, nextUse});
        }
        cout << "Step " << i+1 << " (page=" << page << "): ";
        for (int f : frames) cout << f << " ";
        cout << endl;
    }
    cout << "Total Page Faults = " << faults << endl;
}

int main() {
    vector<int> pages = {1,2,3,4,1,2,5,1,2,3,4,5};
    //LRUPageReplacementBrute(pages, 3);
    //LRUPageReplacement(pages, 3);
    LRUPageReplacementOptimal(pages, 3);
    return 0;
}


