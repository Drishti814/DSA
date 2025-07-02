#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    int reverse_num = 0;
    while(num > 0){
        int last_digit = num%10;
        reverse_num = reverse_num * 10 + last_digit;
        num = num/10;
    }
    cout << "reverse number is " << reverse_num << endl;
}
