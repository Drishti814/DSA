#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.first > p2.first) return true;
    return false;
}

int main(){
    vector<int> v;
    int a[4] = {1,3,5,2};
    sort(v.begin(),v.end());
    sort(a,a+4);
    sort(a+2,a+4);
    sort(a,a+4,greater<int>());     //decreasing order
    for(int i = 0; i<4; i++){
       //cout << a[i] << " ";
    }

    pair<int,int> ar[] = {{1,2},{2,1},{4,1}};
    sort(ar,ar+3,comp);
    //sort according to second element in inc order
    //if second element same sort acc to first in desc order

    int num = 7;
    int cnt = __builtin_popcount(num); //no. of 1s or set bits

    long long numm = 23456456789;
    int cntt = __builtin_popcountll(numm);
    
    string s = "123";
    sort(s.begin(),s.end());
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));

    int maxx = *max_element(a,a+4);
}