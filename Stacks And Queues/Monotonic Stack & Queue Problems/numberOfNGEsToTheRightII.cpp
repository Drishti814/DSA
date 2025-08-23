#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std;

//another meaning of NGEs to right is Take each element → count its first NGE → then for that NGE count its NGE → continue until no NGE → total = number of NGEs in this chain.

//TC O(2N)
//SC O(2N)
vector<int> numOfNGEsToTheRight(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,0);
    stack<int> st;
    int i = n-1;
    while(i>=0){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        ans[i]=st.size();
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
    vector<int> ans = numOfNGEsToTheRight(arr);
    for(auto it: ans){
        cout << it << " ";
    }
}