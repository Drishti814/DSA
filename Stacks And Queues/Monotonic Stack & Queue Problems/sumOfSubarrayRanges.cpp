#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

//brute force
//TC O(N^2)
//SC O(1)
long long sumOfSubarrayRanges(vector<int> & arr){
    int n = arr.size();
    long long sum = 0;
    for(int i = 0;i<n;i++){
        int mini = arr[i];
        int maxi = arr[i];
        for(int j = i+1;j<n;j++){
            mini = min(mini,arr[j]);
            maxi = max(maxi,arr[j]);
            sum = (sum+(maxi-mini));
        }
    }
    return sum;
}

vector<int> previousSmallerOrEqualElement(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    int i = 0;
    while(i<n){
        while(!st.empty() && arr[st.top()] > arr[i]){
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

long long sumOfSubarrayMinOptimal(vector<int> & arr){
    int n = arr.size();
    long long sum = 0;
    vector<int> nse = nextSmallerElement(arr);
    vector<int> pse = previousSmallerOrEqualElement(arr);
    for(int i = 0;i<n;i++){
        long long left = i-pse[i];
        long long right = nse[i]-i;
        long long s1 = (left*right);
        s1 = (arr[i]*s1);
        sum = (sum+s1);
    }
    return sum;
}

vector<int> previousGreaterOrEqualElement(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    int i = 0;
    while(i<n){
        while(!st.empty() && arr[st.top()] < arr[i]){
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

vector<int> nextGreaterElement(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    int i = n-1;
    while(i>=0){
        while(!st.empty() && arr[st.top()] <= arr[i]){
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

long long sumOfSubarrayMaxOptimal(vector<int> & arr){
    int n = arr.size();
    long long sum = 0;
    vector<int> nge = nextGreaterElement(arr);
    vector<int> pge = previousGreaterOrEqualElement(arr);
    for(int i = 0;i<n;i++){
        long long left = i-pge[i];
        long long right = nge[i]-i;
        long long s1 = (left*right);
        s1 = (arr[i]*s1);
        sum = (sum+s1);
    }
    return sum;
}

//optimal
//TC O(10N)
//SC O(10N)
long long sumOfSubarrayRangesOptimal(vector<int>& arr) {
    long long ans = sumOfSubarrayMaxOptimal(arr) - sumOfSubarrayMinOptimal(arr);
    return ans;
}

int main(){
    vector<int> arr = {3,1,2,4};
    //long long ans = sumOfSubarrayRanges(arr);
    long long ans = sumOfSubarrayRangesOptimal(arr);
    cout << ans;
}