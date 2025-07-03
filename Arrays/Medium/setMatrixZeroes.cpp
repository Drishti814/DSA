#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

void setRow(vector<vector<int>> & matrix, int n, int m, int i){
    for(int j = 0;j<n;j++){
        if(matrix[i][j]!=0){
            matrix[i][j] = -1;
        }
    }
}

void setColumn(vector<vector<int>> & matrix, int n, int m, int j){
    for(int i = 0;i<m;i++){
        if(matrix[i][j]!=0){
            matrix[i][j] = -1;
        }
    }
}

//brute force
//TC O((n*m)*(n+m)+(n*m))~O(n^3) approx
//SC O(1)
vector<vector<int>> setMatrixZeroes(vector<vector<int>> & matrix, int m, int n){
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j]==0){
                setRow(matrix,m,n,i);
                setColumn(matrix,m,n,j);
            }
        }
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}

//better
//TC O(2(n*m))~O(n^2)
//SC O(n+m)
vector<vector<int>> setMatrixZeroesBetter(vector<vector<int>> & matrix, int m, int n){
    vector<int> row(m,0);
    vector<int> col(n,0);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(row[i]==1||col[j]==1){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}

//optimal
//TC O(2(n*m))~O(n^2)
//SC O(1)
vector<vector<int>> setMatrixZeroesOptimal(vector<vector<int>> & matrix, int m, int n){
    int col1 = 1;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                if(j!=0){
                    matrix[0][j] = 0;
                }
                else{
                    col1 = 0;
                }
            }
        }
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            if(matrix[i][j]!=0){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j = 0;j<n;j++){
            matrix[0][j]=0;
        }
    }
    if(col1==0){
        for(int i = 0;i<m;i++){
            matrix[i][0]=0;
        }
    }
    return matrix;
}

int main(){
    int m,n;
    cin >> m;
    cin >> n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    //vector<vector<int>> ans = setMatrixZeroes(matrix,m,n);
    //vector<vector<int>> ans = setMatrixZeroesBetter(matrix,m,n);
    vector<vector<int>> ans = setMatrixZeroesOptimal(matrix,m,n);
    for(auto it : ans){
        for(auto element : it){
            cout << element <<" ";
        }
        cout << endl;
    }
}
    