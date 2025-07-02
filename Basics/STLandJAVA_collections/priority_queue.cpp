#include<iostream>
#include<queue>
using namespace std;

//non linear DS
//prioruty of largest number
//push and pop - O(logn)
//top - O(1)

int main(){
    //max heap 
    priority_queue<int> pq;              //pq = {}
    pq.push(1);                 //pq = {1}
    pq.emplace(5);              //pq = {5,1}
    pq.push(3);                 //pq = {3,5,1}
    pq.emplace(8);              //pq = {8,5,3,1}
    pq.top();                   //8
    pq.pop();                   //pq = {5,3,1}
    //restsame as stack size empty swap

    //min heap
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);                 //pq = {1}
    pq.emplace(5);              //pq = {1,5}
    pq.push(3);                 //pq = {1,3,5}
    pq.emplace(8);              //pq = {1,3,5,8}
    pq.top();                   //1
}