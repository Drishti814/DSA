#include<iostream>
#include<algorithm>
using namespace std;

//O(n^2) worst,avg
//O(n) best

void insertion_sort(int arr[], int n){
    for(int i = 0;i<n;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}