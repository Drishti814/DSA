#include<iostream>
#include<vector>
using namespace std;

//brute force
//TC O(N^2)
//SC O(26)
int longestRepeatingCharReplacement(string s, int k){
    int maxlen = 0;
    int n = s.length();
    for(int i = 0;i<n;i++){
        vector<int> hash(26,0);
        int maxFreq = 0;
        for(int j = i;j<n;j++){
            hash[s[j]-'A']++;
            maxFreq = max(maxFreq,hash[s[j]-'A']);
            int changes = (j-i+1) - maxFreq;
            if(changes<=k){
                maxlen = max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;
}

//better
//TC O(2N*26)
//SC O(26)
int longestRepeatingCharReplacementBetter(string s, int k){
    int n = s.length();
    vector<int> hash(26,0);
    int l = 0;
    int r = 0;
    int maxFreq = 0;
    int maxlen = 0;
    while(r<n){
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq,hash[s[r]-'A']);
        if(((r-l+1)-maxFreq)<=k){
            maxlen = max(maxlen,r-l+1);
        }
        while(((r-l+1)-maxFreq)>k){
            hash[s[l]-'A']--;
            maxFreq = 0;
            for(int i = 0;i<26;i++){
                maxFreq = max(maxFreq,hash[i]);
            }
            l++;
        }
        r++;
    }
    return maxlen;
} 

//more better
//TC O(2N)
//SC O(26)
int longestRepeatingCharReplacementMoreBetter(string s, int k){
    int n = s.length();
    vector<int> hash(26,0);
    int l = 0;
    int r = 0;
    int maxFreq = 0;
    int maxlen = 0;
    while(r<n){
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq,hash[s[r]-'A']);
        if(((r-l+1)-maxFreq)<=k){
            maxlen = max(maxlen,r-l+1);
        }
        while(((r-l+1)-maxFreq)>k){
            hash[s[l]-'A']--;   //no need to change maxFreq as no benefit in decreasing it
            l++;
        }
        r++;
    }
    return maxlen;
}

//optimal
//TC O(N)
//SC O(26)
int longestRepeatingCharReplacementOptimal(string s, int k){
    int n = s.length();
    vector<int> hash(26,0);
    int l = 0;
    int r = 0;
    int maxFreq = 0;
    int maxlen = 0;
    while(r<n){
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq,hash[s[r]-'A']);
        if(((r-l+1)-maxFreq)<=k){
            maxlen = max(maxlen,r-l+1);
        }
        if(((r-l+1)-maxFreq)>k){
            hash[s[l]-'A']--;   
            l++;
        }
        r++;
    }
    return maxlen;
}

int main(){
    string s = "AABABBA";
    //int len = longestRepeatingCharReplacement(s,2);
    //int len = longestRepeatingCharReplacementBetter(s,2);
    //int len = longestRepeatingCharReplacementMoreBetter(s,2);
    int len = longestRepeatingCharReplacementOptimal(s,2);
    cout << len;
}