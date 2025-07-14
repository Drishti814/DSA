#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//TC O(m*n)
//SC O(1)
bool searchElement(vector<vector<int>> &matrix, int m, int n, int target){
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j]==target) return true;
        }
    }
    return false;
}

int binarySearch(vector<int> &a, int n, int target){
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] == target) return mid;
        else if(target > a[mid]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

//better
//TC O(m*logn)
//SC O(1)
bool searchElementBetter(vector<vector<int>> &matrix, int m, int n, int target){
    for (int i = 0; i < m; i++){
        if(matrix[i][0]<=target && matrix[i][n-1]){
            return binarySearch(matrix[i],n,target);
        }
    }
    return false;
}

//optimal
//TC O(m+n)
//SC O(1)
bool searchElementOptimal(vector<vector<int>> &matrix, int m, int n, int target){
    int row = 0;
    int col = n-1;
    while(row<n && col>=0){
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]<target) row++;
        else col--;
    }
    return false;
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
    int target;
    cin >> target;
    //bool ans = searchElement(matrix,m,n,target);
    //bool ans = searchElementBetter(matrix,m,n,target);
    bool ans = searchElementOptimal(matrix,m,n,target);
    cout << ans;
}