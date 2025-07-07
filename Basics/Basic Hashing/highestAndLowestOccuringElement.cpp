#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }

    unordered_map<int,int> mpp;
    for(int i = 0;i<n;i++){
        mpp[arr[i]]++;
    }
 
    int min_freq = n;
    int max_freq = 0;
    int min_element = 0;
    int max_element = 0;

    for(auto it : mpp){
        int count = it.second;
        int element = it.first;

         if(count > max_freq){
            max_element = element;
            max_freq = count;
        }
        if(count < min_freq){
            min_element = element;
            min_freq = count;
        }
    } 
    cout << "Max freq is " << max_freq  << " and the element is " << max_element << endl; 
    cout << "Min freq is " << min_freq << " and the element is " << min_element << endl; 
}