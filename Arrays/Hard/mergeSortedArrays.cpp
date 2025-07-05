#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//brute force using extra space
//TC O(n+m)+O(n+m)
//SC O(n+m)
void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> temp;
    int left = 0;
    int right = 0;
    while(left<m && right<n){
        if(nums1[left]<=nums2[right]){
            temp.push_back(nums1[left]);
            left++;
        }
        else{
            temp.push_back(nums2[right]);
            right++;
        }
    }
    while(left < m){
        temp.push_back(nums1[left]);
        left++;
    }
    while (right < n){
        temp.push_back(nums2[right]);
        right++;
    }
    for(int i = 0; i<m+n; i++){
        if(i<m) nums1[i] = temp[i];
        else nums2[i-m] = temp[i];
    }
}

//optimal 1
//TC O(min(m,n)+mlogm+nlogn)
//SC O(1)
void mergeArraysOptimal(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int left = n-1;
    int right = 0;
    while(left>=0 && right<n){
        if(nums1[left]>nums2[right]){
            swap(nums1[left],nums2[right]);
            left--;
            right++;
        }
        else break;
    }
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
}

void swapIfGreater(vector<int> &nums1,vector<int> &nums2, int left, int right){
    if(nums1[left]>nums2[right]){
        swap(nums1[left],nums2[right]);
    }
}

//optimal 2
//TC O(m+n+log2(m+n))
//SC O(1)
void mergeArraysOptimal2(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int len = m+n;
    int gap = (len/2)+(len%2);
    while(gap>0){
        int left = 0;
        int right = left+gap;
        while(right < len){
            if(left<m && right>=m){
                swapIfGreater(nums1,nums2,left,right-m);
            }
            else if(left>=m){
                swapIfGreater(nums2,nums2,left-m,right-m);
            }
            else{
                swapIfGreater(nums1,nums1,left,right);
            }
            left++;
            right++;
        }
        if(gap==1) return;
        gap = (gap/2)+(gap%2);
    }
}

int main(){
    int m,n;
    cin >> m;
    cin >> n;
    vector<int> nums1(m);
    for(int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    vector<int> nums2(n);
    for(int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
    //mergeArrays(nums1,m,nums2,n);
    //mergeArraysOptimal(nums1,m,nums2,n);
    mergeArraysOptimal2(nums1,m,nums2,n);
    for(int i=0;i<m;i++){
        cout << nums1[i] << " ";
    }
    for(int i=0;i<n;i++){
        cout << nums2[i] << " ";
    }
}