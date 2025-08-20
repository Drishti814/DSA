#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

struct meeting {
   int start;
   int end;
   int pos;
};

bool comparison(struct meeting m1, struct meeting m2){
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos<m2.pos) return true;
    return false;
}

//TC O(NlogN + 2N)
//SC O(3N + N)
vector<int> maxMeetings(int s[], int e[], int n){
    struct meeting meet[n];
    for(int i = 0;i<n;i++){
        meet[i].start = s[i];
        meet[i].end = e[i];
        meet[i].pos = i+1;
    }
    sort(meet,meet+n,comparison);
    int cnt = 1;
    int endTime = meet[0].end;
    vector<int> ans;
    ans.push_back(meet[0].pos);
    for(int i = 1;i<n;i++){
        if(meet[i].start>endTime){
            cnt++;
            endTime = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}

int main(){
    int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   vector<int> ans = maxMeetings(start, end, n);
   for(auto it : ans){
        cout << it << " ";
    }
} 