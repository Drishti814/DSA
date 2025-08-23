#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> prefixMax(vector<int> &arr){
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1;i<n;i++){
        prefix[i] = max(prefix[i-1],arr[i]);
    }
    return prefix;
}

vector<int> suffixMax(vector<int> &arr){
    int n = arr.size();
    vector<int> suffix(n);
    suffix[n-1] = arr[n-1];
    for(int i = n-2;i>=0;i--){
        suffix[i] = max(suffix[i+1],arr[i]);
    }
    return suffix;
}

//brute force
//TC O(3N)
//SC O(2N)
int trappingRainwater(vector<int> &arr){
    int n = arr.size();
    int total = 0;
    vector<int> prefix = prefixMax(arr);
    vector<int> suffix = suffixMax(arr);
    for(int i = 0;i<n;i++){
        if(arr[i]<prefix[i] && arr[i]<suffix[i]){
            total += min(prefix[i],suffix[i])-arr[i];
        }
    }
    return total;
}

//better
//TC O(2N)
//SC O(N)
int trappingRainwaterBetter(vector<int> &arr){
    int n = arr.size();
    int total = 0;
    vector<int> suffix = suffixMax(arr);
    int leftmax = arr[0];
    for(int i = 0;i<n;i++){
        leftmax = max(leftmax,arr[i]);
        if(arr[i]<leftmax && arr[i]<suffix[i]){
            total += min(leftmax,suffix[i])-arr[i];
        }
    }
    return total;
}

//optimal
//TC O(N)
//SC O(1)
int trappingRainwaterOptimal(vector<int> &arr){
    int n = arr.size();
    int total = 0;
    int leftmax = 0;
    int rightmax = 0;
    int l = 0;
    int r = n-1;
    while(l<r){
        if(arr[l]<=arr[r]){
            if(leftmax>arr[l]){
                total += leftmax - arr[l];
            }
            else{
                leftmax = arr[l];
            }
            l++;
        }
        else{
            if(rightmax>arr[r]){
                total += rightmax - arr[r];
            }
            else{
                rightmax = arr[r];
            }
            r--;
        }
    }
    return total;
}

int main(){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    //int ans = trappingRainwater(arr);
    //int ans = trappingRainwaterBetter(arr);
    int ans = trappingRainwaterOptimal(arr);
    cout << ans;
}