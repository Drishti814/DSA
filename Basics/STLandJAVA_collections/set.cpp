#include<iostream>
#include<set>
using namespace std;

//sorted and unique order
//O(logn)

int main(){ 
    set<int> s;             //s = {}
    s.insert(1);            //s = {1}              
    s.insert(2);            //s = {1,2}
    s.insert(2);            //s = {1,2}
    s.insert(5);            //s = {1,2,5}
    s.emplace(3);           //s = {1,2,3,5}
    auto it = s.find(3);    //return pointer at 3
    auto it = s.find(6);    //return pointer at place next to end i.e. s.end()
    s.erase(2);             //s = {1,3,5}
    int cnt = s.count(3);   //output 0 or 1
    auto it = s.find(5);
    s.erase(it);
    auto it1 = s.find(1);
    auto it2 = s.find(3);
    s.erase(it1,it2);       //[front,end) includes front not end

    //size and swap similar to vector

    auto it = s.lower_bound(2);
    auto it = s.upper_bound(3);
} 