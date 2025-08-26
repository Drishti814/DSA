#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<map>
using namespace std;

//brute force
//TC O(N^2)     //N = s.size()
//SC O(1)
string minWindowSubsequence(string s, string t){
    int minLen = INT_MAX;
    int sIndex = -1;
    for(int i = 0;i<s.size();i++){
        if(s[i]!=t[0]) continue;
        int j = 0;
        int k = i;
        while(k<s.size() && j<t.size()){
            if(s[k]==t[j]) j++;
            k++;
        }
        if(j==t.size()){
            int end = k-1;
            j = t.size()-1;
            while(end>=i){
                if(s[end]==t[j]){
                    j--;
                    if(j<0) break;
                }
                end--;
            }
            int len = k-end;
            if(len<minLen){
                minLen = len;
                sIndex = end;
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
    string s = "abcdebdde";
    string t = "bde";
    string st = minWindowSubsequence(s,t);
    cout << st;
}