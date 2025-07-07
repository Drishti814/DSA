#include<iostream>
#include<list>
using namespace std;

//it acts as a doubly linked list

int main(){
    list<int> ls;               //ls = {}
    ls.push_back(1);            //ls = {1}
    ls.emplace_back(2);         //ls = {1,2}

    ls.push_front(3);           //ls = {3,1,2}
    ls.emplace_front(4);        //ls = {4,3,1,2}
   
    for(auto it : ls){
        cout << it << " ";
    }

     //rest operations same as vectors
}