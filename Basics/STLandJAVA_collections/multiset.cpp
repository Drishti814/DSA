#include<iostream>
#include<set>
using namespace std;

//sorted order not unique
//O(logn)

int main(){
    multiset<int> ms;        //ms = {}
    ms.insert(1);            //ms = {1}              
    ms.insert(2);            //ms = {1,2}
    ms.insert(2);            //ms = {1,2,2}
    ms.insert(5);            //ms = {1,2,2,5}
    ms.emplace(3);           //ms = {1,2,2,3,5}
    ms.erase(2);             //ms = {1,3,5} erases all 2's
    int cnt = ms.count(3);   //output could be more than 1
    auto it = ms.find(5);
    ms.erase(it);
    auto it1 = ms.find(1);
    auto it2 = ms.find(3);
    ms.erase(it1,it2);       //[front,end) includes front not end

    //rest similar to set
} 