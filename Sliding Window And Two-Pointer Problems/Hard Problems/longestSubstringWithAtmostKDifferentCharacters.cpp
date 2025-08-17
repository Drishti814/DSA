#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

//brute force
//TC O(N^2*log(256))
//SC O(256)
int longestSubstringWithKDiffChar(string s, int k){
    int n = s.size();
    map<char,int> mpp;
    int maxlen = 0;
    for(int i = 0;i<n;i++){
        mpp.clear();
        for(int j = i;j<n;j++){
            mpp[s[j]]++;
            if(mpp.size()<=k){
                int len = j-i+1;
                maxlen = max(len,maxlen);
            }
            else break;
        }
    }
    return maxlen;
}

//better
//TC O(2N+log(256))
//SC O(256)
int longestSubstringWithKDiffCharBetter(string s, int k){
    int n = s.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;
    map<int,int> mpp;
    while(r<n){
        mpp[s[r]]++;
        if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
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
//TC O(N+log(256))
//SC O(256)
int longestSubstringWithKDiffCharOptimal(string s, int k){
    int n = s.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;
    map<int,int> mpp;
    while(r<n){
        mpp[s[r]]++;
        if(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0) mpp.erase(s[l]);
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
    string s = "aaabbccd";
    //int len = longestSubstringWithKDiffChar(s,2);
    //int len = longestSubstringWithKDiffCharBetter(s,2);
    int len = longestSubstringWithKDiffCharOptimal(s,2);
    cout << len;
}