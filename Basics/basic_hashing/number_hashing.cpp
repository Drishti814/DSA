#include<iostream>
using namespace std;

//can't work for array size more than 10^6 in function for int
//can't work for array size more than 10^7 globally for int
//can't work for array size more than 10^7 in function for bool
//can't work for array size more than 10^8 globally for bool

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }

    int hash[9] = {0};
    for(int i = 0; i<n;i++){
        hash[arr[i]]+=1;
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        cout << hash[number]<< " ";
    }
}

/*
//brute force method
//O(q*n) too much 

#include<iostream>
using namespace std;


int func(int number, int arr[]){
    int count = 0;
    int n = sizeof(arr);
    for(int i=0;i < n;i++){
        if(arr[i] == number){
            count+=1;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }
    int number;
    cin >> number;
    int count = func(number,arr);
    cout << count;
}
*/