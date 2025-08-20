#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

//brute force - using two loops and checking for 4 conditions where intervals of trains overlap
//where trains overlap increase count of number of platforms
//4 conditions -  
//  。 t1           t2   。
//  。 t1     。    t2
//     t1     。    t2   。
//     t1   。   。  t2  
//TC O(N^2)
//SC O(1)

//optimal
//TC O(2NlogN + 2N)
//SC O(1)
int platformsRequired(vector<int> &arrival, vector<int> &departure){
    int cnt = 0;
    int maxCnt = 0;
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    int i = 0;
    int j = 0;
    while(i<arrival.size()){
        if(arrival[i]<=departure[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt,cnt);
    }
    return maxCnt;
}

int main(){
    int n = 6;
    vector<int> arrival = {900, 945, 955, 1100, 1500, 1800};
    vector<int> departure = {920, 1200, 1130, 1150, 1900, 2000};
   int ans = platformsRequired(arrival, departure);
   cout << ans;
} 