#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void LRUPageReplacement(vector<int>& pages, int capacity) {
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

void LRUPageReplacementOptimal(vector<int>& pages, int capacity) {
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

int main() {
    vector<int> pages = {1,2,3,4,1,2,5,1,2,3,4,5};
    //LRUPageReplacement(pages, 3);
    LRUPageReplacementOptimal(pages, 3);
    return 0;
}
