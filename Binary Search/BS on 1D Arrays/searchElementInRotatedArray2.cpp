#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//with duplicates
//TC O(logn) best and avg case
//TC O(n/2) worst case
int searchElement(vector<int> &a, int n, int target){
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[mid] == target){
        return mid;
        }
        if(a[low]==a[mid] && a[mid]==a[high]){
            low++;
            high--;
            continue;
        }
        if(a[low] <= a[mid]){
            if(a[low] <= target && a[mid] >= target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(a[high] >= target && a[mid] <= target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
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
    int target;
    cin >> target;
    int index = searchElement(a,n,target);
    cout << index;
}