#include<iostream>
#include<math.h>
using namespace std;

int count_digit(int num){
    int count = (int)(log10(num)+1);
    return count; 
}

int main(){
    int n = 0;
    int num;
    cin >> num;
    while(num > 0){
        int last_digit = num%10;
        n += 1;
        num = num/10;
    }
    cout << "number of digits are " << n << endl;
    cout << "number of digits are " << count_digit(num) << endl;
}

//time complexity = nearly O(log10(n))