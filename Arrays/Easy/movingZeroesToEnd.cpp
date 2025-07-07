#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Brute Force Method
//O(2n) TC
//O(m) extra SC 

void zeroAtEnd(int arr[], int n){
    vector<int> temp;
    for(int i = 0; i < n; i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }  
    }
    int m = temp.size();
    for(int i = 0; i < m; i++){
        arr[i] = temp[i];
    }
    for(int i = m; i<n; i++){
        arr[i] = 0;
    }
}

//Optimal
//O(n) TC
//O(1) SC

void moveZeroes(int arr[], int n){
    int j = -1;
    for(int i = 0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        } 
    }
    if(j==-1) return;
    for(int i = j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
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
    //zeroAtEnd(arr,n);
    moveZeroes(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}