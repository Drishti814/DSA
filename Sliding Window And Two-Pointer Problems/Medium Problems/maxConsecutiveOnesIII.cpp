#include<iostream>
#include<vector>
using namespace std;

//max consecutive ones with k zero bits that can be shifted to one

//brute force
//TC O(N^2)
//SC O(1)
int maxConsecutiveOnes(vector<int> &arr, int k){
    int n = arr.size();
    int maxlen = 0;
    for(int i = 0;i<n;i++){
        int zero = 0;
        for(int j = i;j<n;j++){
            if(arr[j]==0) zero++;
            if(zero<=k){
                int len = j-i+1;
                maxlen = max(maxlen,len);
            }
            else break;
        }
    }
    return maxlen;
}

//better
//TC O(2N)
//SC O(1)
int maxConsecutiveOnesBetter(vector<int> &arr, int k){
    int n = arr.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;
    int zero = 0;
    while(r<n){
        if(arr[r]==0) zero++;
        if(zero<=k){
            int len = r-l+1;
            maxlen = max(len,maxlen);
        }
        else{
            while(zero>k){
                if(arr[l]==0) zero--;
                l++;
            }
        }
        r++;
    }
    return maxlen;
} 

//optimal
//TC O(N)
//SC O(1)
int maxConsecutiveOnesOptimal(vector<int> &arr, int k){
    int n = arr.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;
    int zero = 0;
    while(r<n){
        if(arr[r]==0) zero++;
        if(zero<=k){
            int len = r-l+1;
            maxlen = max(len,maxlen);
        }
        else{
            if(arr[l]==0) zero--;
            l++;
        }
        r++;
    }
    return maxlen;
} 

int main(){
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    //int len = maxConsecutiveOnes(arr,2);
    //int len = maxConsecutiveOnesBetter(arr,2);
    int len = maxConsecutiveOnesOptimal(arr,2);
    cout << len;
}