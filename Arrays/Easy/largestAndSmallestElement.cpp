#include <iostream>
using namespace std;

int largest_element(int arr[], int n){
    int largest = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

int smallest_element(int arr[], int n){
    int smallest = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }
    return smallest;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int largest = largest_element(arr,n);
    int smallest = smallest_element(arr,n);
    cout << largest << endl;
    cout << smallest;
}