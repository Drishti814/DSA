#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<map>
using namespace std;

//brute force
//TC O(N^2*M)     //N = s.size()
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
//TC O(N*M)    //N = s.size(),M = t.size();
//SC O(1)
string minWindowSubsequencegOptimal(string s, string t){
    int minLen = INT_MAX;
    int sIndex = -1;
    int l = 0;
    int r = 0;
    int x = 0;
    while(r<s.size()){
        if(s[r]==t[x]){
            x++;
            if(x==t.size()){
                int end = r;
                x--;
                l = r;
                while(x>=0){
                    if(s[l]==t[x]){
                        x--;
                    }
                    l--;
                }
                l++;
                int len = end-l+1;
                if(len<minLen){
                    minLen = len;
                    sIndex = l;
                }
                r=l;
                x=0;
            }
        }
        r++;
    }
    if(sIndex == -1) return "";
    return s.substr(sIndex,minLen);
}

int main(){
    string s = "abbcdebdde";
    string t = "bde";
    //string st = minWindowSubsequence(s,t);
    string st = minWindowSubsequencegOptimal(s,t);
    cout << st;
}