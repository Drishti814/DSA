#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//brute force
//TC O(k*n)+O(n)
//SC O(n-1)
long double gasStations(vector<int> &a, int n, int k){
    vector<int> howMany(n-1,1);
    for(int gas = 1; gas<=k; gas++){
        long double maxSecLen = -1; 
        int ind = -1;
        for(int i = 0;i<n-1;i++){
            long double diff = (a[i+1]-a[i]);
            long double secLen = diff/(long double)howMany[i];
            if(secLen > maxSecLen){
                maxSecLen = secLen;
                ind = i;
            }
        }
        howMany[ind]++;
    }
    long double ans = -1;
    for(int i = 0;i<n-1;i++){
        long double diff = (a[i+1]-a[i]);
        long double secLen = diff/(long double)howMany[i];
        ans = max(ans,secLen);
    }
    return ans;
}

long double gasStationsBetter(vector<int> &a, int n, int k){
    vector<int> howMany(n-1,1);
    priority_queue<pair<long double,int>> pq;
    for(int i = 0;i<n-1;i++){
        pq.push({(a[i+1]-a[i]),i});
    }
    for(int gas = 1; gas<=k; gas++){
        auto tp = pq.top();
        pq.pop();
        int ind = tp.second;
         howMany[ind]++;
        long double diff = (a[ind+1]-a[ind]);
        long double secLen = diff/(long double)howMany[ind];
        pq.push({secLen,ind});
        }
    return pq.top().first;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int k;
    cin >> k;
    //long double ans = gasStations(a,n,k);
    long double ans = gasStationsBetter(a,n,k);
    cout << ans;
}