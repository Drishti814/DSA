#include<iostream>
#include<vector>
using namespace std;

//brute force
//TC O(N^2)
//SC O(256)
int lengthOfLongestSubstring(string s){
    vector<int> hash(256,0);
    int maxlen = 0;
    int n = s.length();
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(hash[s[j]]==1) break;
            int len = j-i+1;
            maxlen = max(maxlen,len);
            hash[s[j]] = 1;
        }
    }
    return maxlen;
}

//optimal
//TC O(N)
//SC O(256)
int lengthOfLongestSubstringOptimal(string s){
    int n = s.length();
    vector<int> hash(256,-1);
    int l = 0;
    int r = 0;
    int maxlen = 0;
    while(r<n){
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l = hash[s[r]]+1;
            }
        }
        int len = r-l+1;
        maxlen = max(len,maxlen);
        hash[s[r]] = r;
        r++;
    }
    return maxlen;
} 

int main(){
    string s;
    cin >> s;
    //int len = lengthOfLongestSubstring(s);
    int len = lengthOfLongestSubstringOptimal(s);
    cout << len;
}