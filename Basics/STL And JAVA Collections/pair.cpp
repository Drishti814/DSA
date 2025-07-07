#include<iostream>
#include<utility>
using namespace std;

int main(){
    pair<int,int> p = {1,3};
    cout << p.first << endl << p.second << endl;
    pair<int, pair<int,int>> z = {1,{2,3}};
    cout << z.first << endl << z.second.first << endl << z.second.second << endl;
    pair<int,int> arr[] = {{1,2},{2,3},{3,4}};
    cout << arr[2].first;
}