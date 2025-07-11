#include<iostream>
#include<deque>
using namespace std;

//similar to list and vector

int main(){
    deque<int> d;              //d = {}
    d.push_back(1);            //d = {1}
    d.emplace_back(2);         //d = {1,2}

    d.push_front(3);           //d = {3,1,2}
    d.emplace_front(4);        //d = {4,3,1,2}

    d.front();
    d.back();
   
    for(auto it : d){
        cout << it << " ";
    }

     //rest operations same as vectors and lists
}