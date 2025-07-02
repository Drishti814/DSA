#include <iostream>
using namespace std;
int main(){
    int a = 10;
    long b = 1000;
    long long c = 2345678;
    float d = 7.56;
    double e = 567.78;
    string str = "drishti";
    char ch = 'd';
    /*string st ; 
    cin >> st;   //input = "hello diya"
    cout << st << endl;  //output = hello
    string st1, st2 ;
    cin >> st1 >> st2;   //input = "hello diya"
    cout << st1 << " " << st2 << endl;   //output = hello diya */
    string st;
    getline(cin, st);
    cout << st;
    return 0;
}