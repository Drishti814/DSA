#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<map>
using namespace std;

//brute force
//TC O(N^2)     //N = s.size()
//SC O(256)
string minWindowSubstring(string s, string t){
    int minLen = INT_MAX;
    int sIndex = -1;
    for(int i = 0;i<s.size();i++){
        vector<int> hash(256,0);
        for(int j=0;j<t.size();j++){
            hash[t[j]]++;
        }
        int cnt = 0;
        for(int j=i;j<s.size();j++){
            if(hash[s[j]]>0){
                cnt++;
            } 
            hash[s[j]]--;
            if(cnt==t.size()){
                minLen = min(j-i+1,minLen);
                sIndex = i;
                break;
            }
        }
    }
    if(sIndex == -1) return "";
    return s.substr(sIndex,minLen);
}

//optimal
//TC O(2N+M)    //N = s.size(),M = t.size();
//SC O(256)
string minWindowSubstringOptimal(string s, string t){
    int minLen = INT_MAX;
    int sIndex = -1;
    int l = 0;
    int r = 0;
    int cnt = 0;
    vector<int> hash(256,0);
    for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
    while(r<s.size()){
        if(hash[s[r]]>0){
            cnt++;
        }
        hash[s[r]]--;
        while(cnt == t.size()){
            if(r-l+1<minLen){
                minLen = r-l+1;                                      
                sIndex = l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0){
                cnt=cnt-1;
            }
            l++;
        }
        r++;
    }
    if(sIndex == -1) return "";
    return s.substr(sIndex,minLen);
}

int main(){
    string s = "ddaaabbca";
    string t = "abc";
    //string st = minWindowSubstring(s,t);
    string st = minWindowSubstringOptimal(s,t);
    cout << st;
}