#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

//brute force
//TC O(N^2+N)
//SC O(2N)
int celebrity(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<int> knowme(n,0);
    vector<int> iknow(n,0);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j] == 1){
                knowme[j]++;
                iknow[i]++;
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(knowme[i]==n-1 && iknow[i]==0){
            return i;
        }
    }
    return -1;
}

//optimal
//TC O(2N)
//SC O(1)
int celebrityOptimal(vector<vector<int>> &matrix){
    int n = matrix.size();
    int top = 0;
    int down = n-1;
    while(top<down){
        if(matrix[top][down]==1){
            top++;
        }
        else if(matrix[down][top]==1){
            down--;
        }
        else{
            top++;
            down--;
        }
    }
    if(top>down){
        return -1;
    }
    for(int i = 0;i<n;i++){
        if(i==top) continue;
        if(matrix[top][i]==0 && matrix[i][top]==1){
            return top;
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> matrix = {
    {0,1,1,0},
    {0,0,0,0},
    {0,1,0,0},
    {1,1,0,0}
    };
    //int ans = celebrity(matrix);
    int ans = celebrityOptimal(matrix);
    cout << ans;
}