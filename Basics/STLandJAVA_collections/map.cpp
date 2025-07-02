#include<iostream>
#include<map>
using namespace std;

//sorted and unique order
//O(logn)
//key value pair where key is unique

int main(){ 
    map<int,int> mpp;
    map<int,pair<int,int>> mpp2;
    map<pair<int,int>,int> mpp3;

    mpp[1] = 2;
    mpp.insert({3,4});
    //mpp.emplace({2,3});

    //mpp2[{2,3}] = 10;

    for(auto it: mpp){
        cout << it.first << " " << it.second << endl;
    }
    cout << mpp[1] << endl;
    cout << mpp[3] << endl;

    auto it = mpp.find(3);
    //cout << *(it).second << endl;

    auto it = mpp.find(5);
    //cout << *(it).second << endl;       //point at mpp.end()

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(1);

    //erase size swap empty same as above
} 