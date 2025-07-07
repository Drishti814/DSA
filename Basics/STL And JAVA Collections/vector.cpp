#include<iostream>
#include<vector>
using namespace std;

 //vectors have dynamic containers in nature unlike array
 //it acts as a single linked list

int main(){
    //Declaration
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    //cout << v[1] << endl;

    //Declaration of pair
    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);  //doesn't need braces
    //cout << vec[0].first << endl;

    //Predefined(size can still be changed)
    vector<int> v1(5,10); //v1(size,elements)
    vector<int> v2(5);  //v1(size)
    vector<int> v3(v1); //copy of v1 in v3

    //Iterations
    vector<int>::iterator it = v.begin();   //v.begin points at memory address
    //out << *it <<endl;
    it++;
    //cout << *it << endl;

    //types of iterations                       //v = {10,20,30,40,50}
    vector<int>::iterator it1 = v.begin();       //points at 10(it++)
    vector<int>::iterator it2 = v.end();         //points at place after 50(it--)
    //not used 
    // vector<int>::iterator it3 = v.rbegin();      //points at 50(it++)
    // vector<int>::iterator it4 = v.rend();        //points at place before 10(it--)

    //Print an element of vector
    //cout << v[0] << endl << v.at(0) << endl;
    //cout << v.back() << endl;

    //Print whole vector
    for(vector<int>::iterator it = v.begin();it != v.end();it++){
        //cout << *it << endl;
    }
    for(auto it = v.begin();it != v.end();it++){
        //cout << *it << endl;
    }
    for(auto it : v){
        //cout << it << endl;
    }

    //Erase elements                     //v = {10,20,30,40,50,60,70}
    v.erase(v.begin()+1);                //v = {10,30,40,50,60,70}
    v.erase(v.begin()+2, v.begin()+4);   //v = {10,30,60,70} (it erase [start,end)include start exclude end)

    //Insert elements(costly operation due to time complexity)  //v = {10,20,30,40,50,60,70}
    v.insert(v.begin(), 0);              //v = {0,10,20,30,40,50,60,70}
    v.insert(v.begin()+1,2,5);           //v = {0,5,5,10,20,30,40,50,60,70}(position,size,element)
    //cout << v[2];
    vector<int> copy(1,2);               //copy = {1,2}
    v.insert(v.begin()+1,copy.begin(),copy.end());  //v = {0,1,2,5,5,10,20,30,40,50,60,70}

    //other operations
    v.size();           //tells size of vector
    v.pop_back();       //pops out last element
    v1.swap(v2);        //swaps two vectors
    v.clear();          //erases the vector
    v.empty();          //empties the vector
}