//method 1

#include<iostream>
using namespace std;

int n = 0;
void print(int x){
    if(n==x) return;
    n++;
    cout << "hello" << endl;
    print(x);
}

int main(){
    int x;
    cin >> x; 
    print(x);
}

//TC - O(n), SC - O(n)

//method 2

/*
#include<iostream>
using namespace std;

void print(int i, int x){
    if(i>x) return;
    cout << "hello" << endl;
    print(i+1,x);
}

int main(){
    int x;
    cin >> x; 
    print(1,x);
}
 */