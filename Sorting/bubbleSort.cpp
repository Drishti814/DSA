#include<iostream>
#include<algorithm>
using namespace std;

//O(n^2) worst,avg
//O(n) best

void bubble_sort(int arr[], int n){
    for(int i = n-1;i>=1;i--){
        int didswap = 0;
        for(int j = 0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap += 1;
            }
        }
        if(didswap == 0){
            break;
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
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}