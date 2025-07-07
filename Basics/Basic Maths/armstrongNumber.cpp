#include<iostream>
#include<math.h>
using namespace std;

//number whose power of each digit is equal to the no. of digits in the number
//eg. 1634 = 1^4 + 6^4 + 3^4 + 4^4 
//eg. 371 = 3^3 + 7^3 + 1^3

int main(){
    int num;
    cin >> num;
    int n = num;
    int dup = num;
    int new_num = 0;
    int count = 0;
    int last_digit;
    while(num > 0){
        last_digit = num % 10;
        count += 1;
        num = num/10;
    }
    while(n > 0){
        last_digit = n % 10;
        new_num += pow(last_digit,count);
        n = n/10;
    }
    if(dup == new_num){
        cout << "This is an armstrong number" << endl;
    }
    else{
        cout << "This is not an armstrong number" << endl;
    }
}