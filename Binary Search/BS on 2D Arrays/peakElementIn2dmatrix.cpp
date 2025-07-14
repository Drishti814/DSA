#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force will be searching all elements and checking thier top,left,bottom,right
//TC O(m*n*4)
//SC O(1)

//Better will be finding the max element of the matrix bcz it will be peak
//TC O(m*n)
//SC O(1)

int maxElement(vector<vector<int>> &a,int m, int n, int col){
    int maxEl = -1;
    int ind = -1;
    for(int i = 0;i<m;i++){
        if(a[i][col]>maxEl){
            maxEl = a[i][col];
            ind = i;
        }
    }
    return ind;
}

//optimal
//TC O(m*logn)
//SC O(1)
pair<int,int> peakElement(vector<vector<int>> & matrix, int m, int n){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        int row = maxElement(matrix,m,n,mid);
        int left = mid - 1 >= 0 ? matrix[row][mid-1]:-1;//----->// int left,right;
        int right = mid + 1 < n ? matrix[row][mid+1]:-1;//----->// if(mid - 1>=0){
        if(matrix[row][mid]>left && matrix[row][mid]>right){    //      left = matrix[row][mid - 1];
            return {row,mid};                                   // }
        }                                                       // else left = -1;
        else if(matrix[row][mid]<left) high = mid - 1;          // if(mid+1<n){
        else low = mid + 1;                                     //     right = matrix[row][mid + 1];
    }                                                           // }
    return {-1,-1};                                             // else right = -1;   
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
    pair<int,int> el = peakElement(matrix,m,n);
    cout << el.first <<" " << el.second;
}