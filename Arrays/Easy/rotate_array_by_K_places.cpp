#include <iostream>
#include<algorithm>
using namespace std;

//O(2n)
//no extra SC
void Lrotate(int arr[], int k, int n){
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}

//O(2n)
//no extra SC
void Rrotate(int arr[], int k, int n){
    reverse(arr,arr+n);
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
}

//O(n+k)
//O(k) extra SC
void rotate_left_easy(int arr[], int k, int n){
    if (n == 0) return;
    if(k==0) return;
    int temp[k];
    for (int i = 0; i < k; i++){
        temp[i] = arr[i];
    }
    for (int i = k; i < n; i++){
        arr[i-k] = arr[i];
    }
    for (int i = n - k; i < n; i++){
        arr[i] = temp[i-(n-k)];
    }
}

//O(n+k)
//O(k) extra SC
void rotate_right_easy(int arr[], int k, int n){
    if (n == 0) return;
    if(k==0) return;
    int temp[k];
    for (int i = n-k; i < n; i++){
        temp[i-(n-k)] = arr[i];
    }
    for (int i = n-k-1; i >= 0; i--){
        arr[i+k] = arr[i];
    }
    for (int i = 0; i < k; i++){
        arr[i] = temp[i];
    }
}

//O(n*k)
void rotateLeft(int arr[], int k, int n) {
    if(k==0) return;
    for(int count = 0;count<k;count++){
    int temp = arr[0];
        for(int i = 1;i<n;i++){
            arr[i-1] = arr[i];
        }
        arr[n-1] = temp;
    }
}

//O(n*k)
void rotateRight(int arr[], int k, int n) {
    if(k==0) return;
    for(int count = 0;count<k;count++){
    int temp = arr[n-1];
    for(int i = n-1 ;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    k = k % n;
    // rotateLeft(arr, k, n);
    // rotateRight(arr, k, n);
    // rotate_left_easy(arr, k, n);
    //rotate_right_easy(arr,k,n);
    //Lrotate(arr,k,n);
    Rrotate(arr,k,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}