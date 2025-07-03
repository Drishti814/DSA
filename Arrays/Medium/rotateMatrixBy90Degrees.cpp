#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//O(n^2) TC
//O(n^2) SC
vector<vector<int>> rotateMatrix(vector<vector<int>> & matrix, int n){
    vector<vector<int>> a(n,vector<int> (n,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            a[j][n-1-i] = matrix[i][j];
        }
    }
    return a;
}

//optimal 
//TC O(n^2+n^2)
//SC O(1)
vector<vector<int>> rotateMatrixOptimal(vector<vector<int>> & matrix, int n){
    //transpose
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reverse
    for(int i = 0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}

//optimal MY NEW METHOD
//TC O(n^2)
//SC O(1)
vector<vector<int>> rotateMatrixNew(vector<vector<int>> & matrix, int n){
    for(int i = 0;i<n/2;i++){
        for(int j = i;j<n-1-i;j++){
            swap(matrix[i][j],matrix[j][n-1-i]);
            swap(matrix[n-1-j][i],matrix[n-1-i][n-1-j]);
            swap(matrix[i][j],matrix[n-1-i][n-1-j]);
        }
    }
    return matrix;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> ans = rotateMatrix(matrix,n);
    //vector<vector<int>> ans = rotateMatrixOptimal(matrix,n);
    //vector<vector<int>> ans = rotateMatrixNew(matrix,n);
    for(auto it : ans){
        for(auto element : it){
            cout << element <<" ";
        }
        cout << endl;
    }
}
    