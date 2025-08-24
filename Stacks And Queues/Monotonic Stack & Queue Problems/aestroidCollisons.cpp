#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

//TC O(2N)
//SC O(N)
vector<int> aestroidCollisons(vector<int> & arr){
    int n = arr.size();
    vector<int> st;
    for(int i = 0;i<n;i++){
        if(arr[i]>0) st.push_back(arr[i]);
        else{
            while(!st.empty() && st.back()>0 && (abs(arr[i])>st.back())){
                st.pop_back();
            }
            if(!st.empty() && (abs(arr[i])==st.back())){
                st.pop_back();
            }
            else if(st.empty() || st.back()<0){
                st.push_back(arr[i]);
            }
        }
    }
    return st;
}

int main(){
    vector<int> arr = {-4,7,1,1,2,-3,-7,17,15,-16};
    vector<int> ans = aestroidCollisons(arr);
    for(auto it : ans){
        cout << it << " ";
    }
}