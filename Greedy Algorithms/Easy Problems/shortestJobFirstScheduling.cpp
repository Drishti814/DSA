#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//TC O(N)
//SC O(1)
int shortestJobFirst(vector<int> &job){
    sort(job.begin(),job.end());
    int t = 0;
    int netTime = 0;
    for(int i = 0;i<job.size();i++){
        netTime += t;
        t += job[i];
    }
    return netTime/job.size();
}

int main(){
    vector<int> job = {4,3,7,1,2};
    int ans = shortestJobFirst(job);
    cout << ans;
}
