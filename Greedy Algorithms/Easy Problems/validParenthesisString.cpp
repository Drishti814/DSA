#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

bool checkValidStringHelper(string s, int index, int cnt){
    if(cnt < 0) return false;
    if(index == s.length()){
        if(cnt==0) return true;
        return false;
    }
    if(s[index]=='(') return checkValidStringHelper(s,index+1,cnt+1);
     if(s[index]==')') return checkValidStringHelper(s,index+1,cnt-1);
     return (checkValidStringHelper(s,index+1,cnt+1)||checkValidStringHelper(s,index+1,cnt-1)||checkValidStringHelper(s,index+1,cnt));
}

//TC O(3^N)
//SC O(N)
bool checkValidString(string s){
    if(checkValidStringHelper(s,0,0)) return true;
    return false;
}

//better DP solution    (haven't studied DP yet)
//TC O(N^2)
//SC O(N^2)

//optimal
//TC O(N)
//SC O(1)
bool checkValidStringOptimal(string s){
    int min = 0;
    int max = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i]=='('){
            min++;
            max++;
        }
        else if(s[i]==')'){
            min--;
            max--;
        }
        else{
            min--;
            max++;
        }
        if(min < 0) min = 0;
        if(max < 0) return false;
    }
    return (min==0);
}

int main(){
    string s = "(*()";
    //bool ans = checkValidString(s);
    bool ans = checkValidStringOptimal(s);
    cout << ans;
} 