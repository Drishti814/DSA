#include <iostream>
#include<climits>
using namespace std;


int secondLargest_element(int arr[], int n){
    int largest = arr[0];
    int secondLargest = -1;
    for(int i = 0;i<n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }
    }
    return secondLargest;
}

int secondSmallest_element(int arr[], int n){
    int smallest = arr[0];
    int secondSmallest = INT_MAX;
    for(int i = 0;i<n;i++){
        if(arr[i] < smallest){
            secondSmallest = smallest;
            smallest = arr[i];
        }
    }
    return secondSmallest;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int secondLargest = secondLargest_element(arr,n);
    int secondSmallest = secondSmallest_element(arr,n);
    cout << secondLargest << endl;
    cout << secondSmallest;
}