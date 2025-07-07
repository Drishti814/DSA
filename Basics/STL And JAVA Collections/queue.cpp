#include<iostream>
#include<queue>
using namespace std;

//FIFO (First in first out)
//O(1)

int main(){
    queue<int> q;              //q = {}
    q.push(1);                 //q = {1}
    q.emplace(2);              //q = {1,2}
    q.back();                  //2
    q.front();                 //1
    q.pop();                   //q = {2}

    //restsame as stack size empty swap
}