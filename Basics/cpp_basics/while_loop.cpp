#include<iostream>
using namespace std;

int main(){
    //while loop
    int i=0;
    while(i<=5){
        cout << "hey" << i << endl;
        i+=1;
    }
    cout << i << endl;

    //do while loop(minimum 1 time execution)
    int j=2;
    do{
        cout << "hello" << j << endl;
        j+=1;
    }while(j<=1);
    cout << j << endl;
}