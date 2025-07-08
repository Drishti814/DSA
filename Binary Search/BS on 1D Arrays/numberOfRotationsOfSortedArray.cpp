#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//unique elements
int rotationsNum(vector<int> &a, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[low]<=a[high]){
            ans = min(ans,a[low]);
            index = low;
            break;
        }
        if(a[low] <= a[mid]){
            ans = min(ans, a[low]);
            index = low;
            low = mid + 1;
        }
        else{
            ans = min(ans, a[mid]);
            index = mid;
            high = mid - 1;
        }
    }
    return index;
}

//duplicate elements
int rotationsNumDuplicates(vector<int> &a, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high){
        int mid = low + (high-low)/2;
        if(a[low]==a[mid] && a[mid]==a[high]){
            ans = min(ans,a[low]);
            index = low;
            low++;
            high--;
            continue;
        }
        if(a[low] < a[high]){
            ans = min(ans,a[low]);
            index = low;
            break;
        }
        if(a[low] <= a[mid]){
            ans = min(ans, a[low]);
            index = low;
            low = mid + 1;
        }
        else{
            ans = min(ans, a[mid]);
            index = mid;
            high = mid - 1;
        }
    }
    return index;
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
    //int index = rotationsNum(a,n);
    int index = rotationsNumDuplicates(a,n);
    cout << index;
}