#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<climits>
using namespace std;

bool linearSearch(vector<int> &a,int n,int num){
    for(int i=0;i<n;i++){
            if(a[i]==num) return true;
        }
        return false;
}

//brute force
//O(n^2) TC
//O(1) SC
int longestSequence(vector<int> &a,int n){
    int longest = 1;
    for(int i = 0;i<n;i++){
        int num = a[i];
        int count = 1;
        while(linearSearch(a,n,num+1)==true){
            num++;
            count++;
        }
        longest = max(longest,count);
    }
    return longest;
}

//better
//O(nlogn+n) TC
//O(1) SC
int longestSequenceBetter(vector<int> &a,int n){
    if(n==0) return 0;
    sort(a.begin(),a.end());
    int longest = 1;
    int count = 0;
    int lastElement = INT_MIN;
    for(int i = 0;i<n;i++){
        if(a[i] == lastElement+1){
            count++;
            lastElement = a[i];
        }
        else if(a[i] != lastElement){
            count = 1;
            lastElement = a[i];
        }
        longest = max(longest,count);
    }
    return longest;
}

//optimal
//O(3n) TC
//O(n) SC
int longestSequenceOptimal(vector<int> &a,int n){
    if(n==0) return 0;
    unordered_set<int> st;
    int longest = 1;
    for(int i = 0;i<n;i++){
        st.insert(a[i]);
    }
    for(auto it:st){
        if(st.find(it-1) == st.end()){
            int count = 1;
            int x = it;
            while(st.find(x+1)!=st.end()){
                x++;
                count++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    //int m = longestSequence(a,n);
    int m = longestSequenceOptimal(a,n);
    cout << m;
}