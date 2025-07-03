#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

//TC O(n^2)
//SC O(n^2)
vector<int> spiralMatrix(vector<vector<int>> & matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0;
    int right = n-1;
    int bottom = m-1;
    int left = 0;
    vector<int> ans;
    while(top<=bottom && left <=right){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
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
    vector<int> ans = spiralMatrix(matrix);
    for(auto it : ans){
        cout << it <<" ";
        
    }
}
    