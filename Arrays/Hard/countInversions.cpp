#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//brute force
//TC O(n^2)
//SC O(1)
int countInversions(vector<int> &arr,int n){
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]>arr[j]) cnt++;
        }
    }
    return cnt;
}

int merge(vector<int> &arr, int low, int mid, int high){
    int cnt = 0;
    int n = sizeof(arr);
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += mid - left + 1;
            right++; 
        }
    }
    while(left<= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i<=high; i++){
        arr[i] = temp[i-low];
    }
    return cnt;
}

int merge_sort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low>=high) return cnt;
        int mid = (low+high)/2;
        cnt += merge_sort(arr,low,mid);
        cnt += merge_sort(arr,mid+1,high);
        cnt += merge(arr,low,mid,high);
        return cnt;
}

//better using merge sort
//it destroys the original array so take a copy of the array
//TC O(nlogn)
//SC O(n)
int countInversionsBetter(vector<int> &arr,int n){
    return merge_sort(arr,0,n-1);
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    //int ans = countInversions(a,n);
    int ans = countInversionsBetter(a,n);
    cout << ans;
}