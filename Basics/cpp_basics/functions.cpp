#include<iostream>
using namespace std;

//void function and non parameterized
void print(){
    cout << "heyy" << endl;
}

//void parameterized
void printname(string s){
    cout << "hey " << s << endl;
}

//return 
int sum(int x, int y){
    int z = x + y;
    return z;
}

//call by value
void doPrint(string s){
    s[0] = 't';
    cout << s << endl;
}

//call by reference
void doPrintt(string &st){
    st[0] = 't';
    cout << st << endl;
}

int main(){

    print();

    string str1 = "raj";
    string str2 = "taj";
    printname(str1);
    printname(str2);

    int x = 2;
    int y = 3;
    int result = sum(x,y);
    cout << result << endl;

    //predefined
    int r1 = max(x, y);
    cout << r1 << endl;
    int r2 = min(x, y);
    cout << r2 << endl;

    //call by value
    string s = "Raj";
    cout << s << endl;
    doPrint(s);
    cout << s << endl;

    //call by reference
    string st = "Raj";
    cout << st << endl;
    doPrintt(st);
    cout << st << endl;
}