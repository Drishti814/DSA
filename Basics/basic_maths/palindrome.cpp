#include<iostream>
#include<math.h>
using namespace std;

//number which when read from start and end are same
//eg. 1331 when reversed = 1331

int main(){
    int num;
    cin >> num;
    int n = num;
    int reverse_num = 0;
    while(num > 0){
        int last_digit = num%10;
        reverse_num = reverse_num * 10 + last_digit;
        num = num/10;
    }
    if(n == reverse_num){
        cout << "This is a palindrome" << endl;
    }
    else{
        cout << "This is not a palindrome" << endl;
    }
}