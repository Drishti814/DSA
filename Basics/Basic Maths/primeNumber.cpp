#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int num;
    cin >> num;
    int count = 0;
    //O(n) - brute force approach
    for(int n = 1;n<=num;n++){
        if(num % n == 0){
            count+=1;
        }
    }
    if(count == 2){
        cout << "This is a prime number." << endl;
    }
    else{
        cout << "This is not a prime number." << endl;
    }

    //optimal approach
    //overall - O(nlogn+sqrt(n) but factors in sqrt(n) time)
    //O(sqrt(n))
    for(int i = 1;i<=sqrt(num);i++){
        if(num % i == 0){
            count+=1;
            if(num/i != i){
                count+=1;
            }
        }
    }
    if(count == 2){
        cout << "This is a prime number." << endl;
    }
    else{
        cout << "This is not a prime number." << endl;
    }
}

