#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

long long nCr(int n, int r){
    long long result = 1;
    for(int i = 0;i<r;i++){
        result = result*(n-i);
        result = result/(i+1);
    }
    return result;
}

//Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
//TC O(r)
//SC O(1)
int printElement(int r, int c){
    if(c > r || c < 1) return 0;
    return nCr(r-1,c-1);
}

//Variation 2: Given the row number n. Print the nth row of Pascal’s triangle.
//TC O(n*r)
//SC O(1)
vector<int> printRow(int n){
    vector<int> ansRow;
    for(int c = 1;c<=n;c++){
        ansRow.push_back(nCr(n-1,c-1));
    }
    return ansRow;
}

//TC O(n)
//SC O(1)
vector<int> printRowBetter(int row){
    long long ans  = 1;
    vector<int> ansRow;
    ansRow.push_back(ans);
    for(int col = 1;col < row;col++){
        ans = ans*(row-col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

//Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
//TC O(n*n*r) ~ O(n^3)
//SC O(1) only using space to store the answer
vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;
    for(int i = 1;i<=n;i++){
        ans.push_back(printRow(i));
    }
    return ans;
}

//TC O(n^2)
//SC O(1) only using space to store the answer
vector<vector<int>> pascalTriangleBetter(int n){
    vector<vector<int>> ans;
    for(int i = 1;i<=n;i++){
        ans.push_back(printRowBetter(i));
    }
    return ans;
}

int main(){
    int r,c;
    cin >> r;
    cin >> c;
    //int ans = printElement(r,c);
    //cout << ans << endl;;
    int row;
    cin >> row;
    int n;
    cin >> n;
    //printRow(n);
    // vector<int> result = printRowBetter(n);
    // for(auto it : result){
    //     cout << it << " ";
    // }
    //vector<vector<int>> output =  pascalTriangle(n);
    vector<vector<int>> output =  pascalTriangleBetter(n);
    for(auto it : output){
       for(auto element : it){
        cout << element << " ";
       }
       cout << endl;
    }
}