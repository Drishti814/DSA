#include<iostream>
#include<vector>
#include<set>
using namespace std;

//optimal approach
//O(n1+n2) TC
//O(1) SC
vector<int> intersectionArraysOptimal(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    vector<int> temp;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(a[i]==b[j]){
            temp.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return temp;
}

//brute force
//O(n1*n2) TC
//O(n2) visited array SC
vector<int> intersectionArrays(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    vector<int> temp;
    int visited[n2];
    visited[n2] = {0};
    for(int i = 0; i<n1;i++){
        for(int j = 0;j<n2;j++){
            if(a[i]==b[j] && visited[j]==0){
                temp.push_back(a[i]);
                visited[j]=1;
                break;
            }
            if(b[j]>a[i]) break;
        }
    }
    return temp;
}

int main(){
    int n1;
    cin >> n1;
    vector<int> a;
    for(int i = 0;i<n1;i++){
        int x;
        cin >>x;
        a.push_back(x);
    }
    int n2;
    cin >> n2;
    vector<int> b;
    for(int i = 0;i<n2;i++){
        int x;
        cin >>x;
        b.push_back(x);
    }
    //vector<int> c=intersectionArrays(a, b);
    vector<int> c = intersectionArraysOptimal(a, b);
    for(auto it : c){
        cout << it << " ";
    }
}