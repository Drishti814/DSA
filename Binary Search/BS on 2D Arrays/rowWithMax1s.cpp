#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//TC O(m*n)
//SC O(1)
int rowWithMax1s(vector<vector<int>> &matrix, int m, int n){
    int max_cnt = 0;
    int ind = -1;
    for(int i = 0;i<m;i++){
        int cnt = 0;
        for(int j = 0;j<n;j++){
            cnt += matrix[i][j];
        }
        if(cnt > max_cnt){
            max_cnt = cnt;
            ind = i;
        }
    }
    return ind;
}

int lowerBound(vector<int> &a, int n, int target){
    int ans = n;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] >= target){
            ans = mid;
            high = mid-1;
        } 
        else low = mid+1;
    }
    return ans;
}

//optimal
//TC O(m*logn)
//SC O(1)
int rowWithMax1sOptimal(vector<vector<int>> &matrix, int m, int n){
    int max_cnt = 0;
    int ind = -1;
    for(int i = 0;i<m;i++){
        int cnt = m-lowerBound(matrix[i],n,1);
        if(cnt > max_cnt){
            max_cnt = cnt;
            ind = i;
        }
    }
    return ind;
}

int main(){
    int m, n;
    cin >> m;
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    //int row = rowWithMax1s(matrix,m,n);
    int row = rowWithMax1sOptimal(matrix,m,n);
    cout << row;
}