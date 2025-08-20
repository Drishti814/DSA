#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b){
    return (a.profit>b.profit);
}

//TC O(NlogN + (N*maxDeadline))
//SC O(maxDeadline)
//optimization can be done using DSUs in graphs (not studied yet)
pair<int,int> jobScheduling(Job arr[], int n){
    sort(arr,arr+n,comparison);
    int totalProfit = 0;
    int cntJobs = 0;
    int maxDeadline = -1;
    for(int i = 0;i<n;i++){
        maxDeadline = max(maxDeadline,arr[i].deadline);
    }
    vector<int> hash(maxDeadline+1,-1);
    for(int i = 0;i<n;i++){
        for(int j = arr[i].deadline;j>0;j--){
            if(hash[j]==-1){
                cntJobs++;
                hash[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }
    return {cntJobs,totalProfit};
}

int main(){
    int n = 4;
    vector<Job> arr = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};
    pair < int, int > ans = jobScheduling(arr.data(), n);
    cout << ans.first << " " << ans.second << endl;

} 