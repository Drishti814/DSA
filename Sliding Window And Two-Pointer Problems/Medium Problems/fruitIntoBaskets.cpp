#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

//brute force
//TC O(N^2)
//SC O(3)
int fruitIntoBaskets(vector<int> &arr, int k){
    int n = arr.size();
    int maxlen = 0;
    for(int i = 0;i<n;i++){
        set<int> st;
        for(int j = i;j<n;j++){
            st.insert(arr[j]);
            if(st.size()<=k){
                int len = j-i+1;
                maxlen = max(len,maxlen);
            }
            else break;
        }
    }
    return maxlen;
}

//better
//TC O(2N)
//SC O(3)
int fruitIntoBasketsBetter(vector<int> &arr, int k){
    int n = arr.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;
    map<int,int> mpp;
    while(r<n){
        mpp[arr[r]]++;
        if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                l++; 
            }
        }
        if(mpp.size()<=k){
            int len = r-l+1;
            maxlen = max(len,maxlen);
        }
        r++;
    }
    return maxlen;
} 

//optimal
//TC O(N)
//SC O(1) or O(3)
int fruitIntoBasketsOptimal(vector<int> &arr, int k){
    int n = arr.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;
    map<int,int> mpp;
    while(r<n){
        mpp[arr[r]]++;
        if(mpp.size()>k){
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0) mpp.erase(arr[l]);
            l++; 
        }
        if(mpp.size()<=k){
            int len = r-l+1;
            maxlen = max(len,maxlen);
        }
        r++;
    }
    return maxlen;
} 

int main(){
    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
    //int len = fruitIntoBaskets(arr,2);
    //int len = fruitIntoBasketsBetter(arr,2);
    int len = fruitIntoBasketsOptimal(arr,2);
    cout << len;
}