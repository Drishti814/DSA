#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

//brute force
//TC O(N^2)
//SC O(1)
int numOfSubstrings(string s, int k){
    int n = s.size();
    int cnt = 0;
    for(int i = 0;i<n;i++){
        vector<int> hash(3,0);
        for(int j = i;j<n;j++){
            hash[s[j]-'a'] = 1;
            if(hash[0]+hash[1]+hash[2]==3){
                cnt = cnt+1;
            }
        }
    }
    return cnt;
}

//better
//TC ~ O(N^2) slightly better
//SC O(1)
int numOfSubstringsBetter(string s, int k){
    int n = s.size();
    int cnt = 0;
    for(int i = 0;i<n;i++){
        vector<int> hash(3,0);
        for(int j = i;j<n;j++){
            hash[s[j]-'a'] = 1;
            if(hash[0]+hash[1]+hash[2]==3){
                cnt = cnt+(n-j);
                break;
            }
        }
    }
    return cnt;
} 

//optimal
//TC O(N+log(256))
//SC O(256)
int numOfSubstringsOptimal(string s, int k){
    int n = s.size();
    vector<int> lastSeen(3,-1);
    int cnt = 0;
    for(int i = 0;i<n;i++){
        lastSeen[s[i]-'a'] = i;
        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
            cnt += 1+min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
        }
    }
    return cnt;
} 

int main(){
    string s = "bbacba";
    //int ans = numOfSubstrings(s,2);
    //int ans = numOfSubstringsBetter(s,2);
    int ans = numOfSubstringsOptimal(s,2);
    cout << ans;
}