#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std;

//brute force
//TC O(N^2)
//SC O(N)
vector<int> previousSmallerElement(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    for(int i = 0;i<n;i++){
        for(int j = i-1;j>=0;j--){
            if(arr[i]>arr[j]){
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
vector<int> previousSmallerElementOptimal(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    int i = 0;
    while(i<n){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else ans[i]=st.top();
        st.push(arr[i]);
        i++;
    }
    return ans;
}

int main(){
    vector<int> arr = {4,5,2,10,8};
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
    //vector<int> ans = previousSmallerElement(arr);
    vector<int> ans = previousSmallerElementOptimal(arr);
    for(auto it: ans){
        cout << it << " ";
    }
}