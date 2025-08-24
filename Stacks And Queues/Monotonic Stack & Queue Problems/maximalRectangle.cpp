#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> & arr){
    int n = arr.size();
    long long maxi = 0;
    stack<int> st;
    int pse = -1;
    int nse = n;
    int val;
    for(int i = 0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int element = st.top();
            st.pop();
            nse = i;
            pse = st.empty()?-1:st.top();
            maxi = max(maxi,(long long)(arr[element]*(nse-pse-1)));
        }
        st.push(i);
    }
    while(!st.empty()){
        nse = n;
        int element = st.top();
        st.pop();
        pse = st.empty()?-1: st.top();
        maxi = max(maxi,(long long)(arr[element]*(nse-pse-1)));
    }
    return maxi;
}

//TC O(m*n + m*2n)
//SC O(m*n + n)
int maximalRectangle(vector<vector<char>>& matrix){
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    vector<vector<int>> sumMatrix(m,vector<int> (n,0));
    for(int j = 0;j<n;j++){
        int sum = 0;
        for(int i = 0;i<m;i++){
            if(matrix[i][j]=='1'){
                sum += 1;
            }
            else sum=0;
            sumMatrix[i][j] = sum;
        }
    }
    int maxArea = 0;
    for(int i = 0;i<m;i++){
        maxArea = max(maxArea,largestRectangleArea(sumMatrix[i]));
    }
    return maxArea;
}

int main(){
    vector<vector<char>> matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
    };
    int ans = maximalRectangle(matrix);
    cout << ans;
}