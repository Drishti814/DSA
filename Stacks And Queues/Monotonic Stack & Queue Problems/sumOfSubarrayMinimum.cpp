#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

//brute force
//TC O(N^2)
//SC O(1)
int sumOfSubarrayMin(vector<int> & arr){
    int n = arr.size();
    long long mod = (int)(1e9 + 7); 
    int sum = 0;
    for(int i = 0;i<n;i++){
        int mini = arr[i];
        for(int j = i;j<n;j++){
            mini = min(mini,arr[j]);
            sum = (sum+mini)%mod;
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
    vector<int> ans(n,-1);
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

//optimal
//TC O(5N)
//SC O(5N)
int sumOfSubarrayMinOptimal(vector<int> & arr){
    int n = arr.size();
    long long mod = (1e9 + 7); 
    long long sum = 0;
    vector<int> nse = nextSmallerElement(arr);
    vector<int> pse = previousSmallerOrEqualElement(arr);
    for(int i = 0;i<n;i++){
        long long left = i-pse[i];
        long long right = nse[i]-i;
        long long s1 = (left*right)%mod;
        s1 = (arr[i]*s1)%mod;
        sum = (sum+s1)%mod;
    }
    return (int)sum;
}

int main(){
    vector<int> arr = {3,1,2,4};
    //int ans = sumOfSubarrayMin(arr);
    int ans = sumOfSubarrayMinOptimal(arr);
    cout << ans;
}