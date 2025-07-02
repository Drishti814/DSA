#include<iostream>
#include<vector>
#include<set>
using namespace std;

//optimal approach
//O(n1+n2) TC
//O(n1+n2) SC for returning
vector<int> unionArraysOptimal(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    vector<int> temp;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(temp.size()==0||temp.back()!=a[i]){
                temp.push_back(a[i]);
            }
            i++;
        }
        else{
            if(temp.size()==0||temp.back()!=b[j]){
                temp.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(temp.back()!=a[i]){
                temp.push_back(a[i]);
        }
        i++;
    }
    while(j<n2){
        if(temp.back()!=b[j]){
                temp.push_back(b[j]);
        }
        j++;
    }
    return temp;
}

//brute force
//O(n1logn1+ n2logn2) TC
//O(m+n) Union array list SC
vector<int> unionArrays(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;
    for(int i = 0; i<n1;i++){
        st.insert(a[i]);
    }
    for(int i = 0; i<n2;i++){
        st.insert(b[i]);
    }
    vector<int> temp;
    for(auto it : st){
        temp.push_back(it);
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
    //vector<int> c=unionArrays(a, b);
    vector<int> c = unionArraysOptimal(a, b);
    for(auto it : c){
        cout << it << " ";
    }
}