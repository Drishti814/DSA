#include <iostream>
using namespace std;

bool arr_sorted(int arr[],int n){
    int count = 0;
    for(int i = 1; i<n;i++){
        if(arr[i]>=arr[(i+1)%n]){
            count++;
        }
    }
    return count<=1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int s = arr_sorted(arr,n);
    cout << s;
}