#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//TC O(m*n) + O(m*n(log(m*n)))
//SC O(m*n)
int medianMatrix(vector<vector<int>> matrix, int m, int n){
    vector<int> arr;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            arr.push_back(matrix[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    return arr[(m*n)/2];
}

int upperBound(vector<int> &a, int n, int target){
    int ans = n;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] > target){
            ans = mid;
            high = mid-1;
        } 
        else low = mid+1;
    }
    return ans;
}

int smallEqualCnter(vector<vector<int>> &matrix, int m, int n, int num){
    int cnt = 0;
    for(int i = 0;i<m;i++){
        cnt += upperBound(matrix[i],n,num);
    }
    return cnt;
}

//optimal
int medianMatrixOptimal(vector<vector<int>> &matrix, int m, int n){
    int low = INT_MAX,high = INT_MIN;
    for(int i = 0;i<m;i++){
        low = min(matrix[i][0],low);
        high = max(matrix[i][n-1],high);
    }
    int required = (m*n)/2;
    while(low <= high){
        int mid = (low+high)/2;
        int smallEqualcnt = smallEqualCnter(matrix,m,n,mid);
        if(smallEqualcnt<=required) low = mid+1;
        else high = mid-1;
    }
    return low;
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
    //int ans = medianMatrix(matrix,m,n);
    int ans = medianMatrixOptimal(matrix,m,n);
    cout << ans;
}