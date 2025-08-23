#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std;

//brute force
//TC O(N^2)
//SC O(N)
vector<int> nextGreaterElement(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]<arr[j]){
                ans[i]=arr[j];
                break;
            }
        }
    }
    return ans;
}

//optimal
//TC O(2N)
//SC O(2N)
vector<int> nextGreaterElementOptimal(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    int i = n-1;
    while(i>=0){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else ans[i]=st.top();
        st.push(arr[i]);
        i--;
    }
    return ans;
}

int main(){
    vector<int> arr = {6,0,8,1,3};
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
    //vector<int> ans = nextGreaterElement(arr);
    vector<int> ans = nextGreaterElementOptimal(arr);
    for(auto it: ans){
        cout << it << " ";
    }
}