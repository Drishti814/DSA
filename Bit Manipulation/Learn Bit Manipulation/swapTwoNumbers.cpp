#include<iostream>
#include<algorithm>
using namespace std;

//using 3rd variable
//TC O(1)
//SC O(1)
//temp = x
//x = y
//y = temp

//without using 3rd variable(arthmetic)
//TC O(1)
//SC O(1)
//a = a+b
//b = a-b
//a = a-b

//using xor operator
//TC O(1)
//SC O(1)
void swapTwoNum(int &x, int &y){
    x = x^y;
    y = x^y;
    x = x^y;
}

int main(){
    int x;
    int y;
    cin >> x >> y;
    cout << " before swapping: " << x << " " << y << endl;
    swapTwoNum(x,y);
    cout << " after swapping: " << x << " " << y;
}