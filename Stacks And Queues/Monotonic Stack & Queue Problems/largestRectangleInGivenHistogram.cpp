#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> previousSmallerElement(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    int i = 0;
    while(i<n){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else ans[i]=st.top();
        st.push(i);
        i++;
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,n);
    stack<int> st;
    int i = n-1;
    while(i>=0){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=n;
        }
        else ans[i]=st.top();
        st.push(i);
        i--;
    }
    return ans;
}

//brute force
//TC O(5N)
//SC O(4N)
int largestRectangleArea(vector<int> & arr){
    int n = arr.size();
    long long maxi = 0;
    vector<int> nse = nextSmallerElement(arr);
    vector<int> pse = previousSmallerElement(arr);
    for(int i = 0;i<n;i++){
        maxi = max(maxi,(long long)(arr[i]*(nse[i]-pse[i]-1)));
    }
    return maxi;
}

//optimal
//TC O(2N)
//SC O(N)
int largestRectangleAreaOptimal(vector<int> & arr){
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

int main(){
    vector<int> arr = {2,1,5,6,2,3};
    //int ans = largestRectangleArea(arr);
    int ans = largestRectangleAreaOptimal(arr);
    cout << ans;
}