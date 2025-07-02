#include<iostream>
#include<map>
using namespace std;

//map - O(logn)
//unordered_map(doesn't waste time in sorting) - O(1)......O(n) few chances when collision
//unordered map - <pair<int,int>,int> doesn't work so use map else use this only except some cases

int main(){
    //for number hashing
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }

    map<int,int> mpp;
    for(int i = 0;i<n;i++){
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }

    //for character hashing
    string s;
    cin >> s;
    int q;
    cin >> q;

    map<char, int> mpp;
    int n = s.size();
    for(int i = 0;i<n;i++){
        mpp[s[i]]++;
    }
    while(q--){
        char c;
        cin >> c;
        cout << mpp[c] << endl;
    }
}