#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

//brute force
//TC O(3N)
//TC O(2N)
int countCandy(vector<int> &ratings){
    int n = ratings.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0] = 1;
    right[n-1] = 1;
    for(int i = 1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            left[i] = left[i-1] + 1;
        }
        else left[i] = 1;
    }
    for(int i = n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            right[i] = right[i+1] + 1;
        }
        else right[i] = 1;
    }
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += max(left[i],right[i]);
    }
    return sum;
}

//better
//TC O(2N)
//TC O(N)
int countCandyBetter(vector<int> &ratings){
    int n = ratings.size();
    vector<int> left(n,0);
    left[0] = 1;
    for(int i = 1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            left[i] = left[i-1] + 1;
        }
        else left[i] = 1;
    }
    int curr = 1;
    int sum = max(1,left[n-1]);
    for(int i = n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            curr++;
        }
        else curr = 1;
        sum += max(left[i],curr);
    }
    return sum;
}

//optimal
//TC O(N)
//SC O(1)
int countCandyOptimal(vector<int> &ratings){
    int n = ratings.size();
    int sum = 1;
    int i = 1;
    while(i<n){
        if(ratings[i]==ratings[i-1]){
            sum += 1;
            i++;
            continue;
        }
        int peak = 1;
        while(i<n && ratings[i]>ratings[i-1]){
            peak++;
            sum += peak;
            i++;
        }
        int down = 1;
        while(i<n && ratings[i]<ratings[i-1]){
            sum += down;
            i++;
            down++;
        }
        if(down > peak) sum += (down-peak);
    }
    return sum;
}

int main(){
    int n = 6;
    vector<int> ratings = {0,2,4,3,2,1,1,3,5,6,4,0,0};
    //int ans = countCandy(ratings);
    //int ans = countCandyBetter(ratings);
    int ans = countCandyOptimal(ratings);
    cout << ans;
} 