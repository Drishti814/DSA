#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//unique elements
int minElement(vector<int> &a, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while (low <= high){
        int mid = (low + high)/2;
        if(a[low]<=a[high]){
            ans = min(ans,a[low]);
            break;
        }
        if(a[low] <= a[mid]){
            ans = min(ans, a[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, a[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

//duplicate elements
int minElementDuplicates(vector<int> &a, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while (low <= high){
        int mid = low + (high-low)/2;
        if(a[low]==a[mid] && a[mid]==a[high]){
            ans = min(ans,a[low]);
            low++;
            high--;
            continue;
        }
        if(a[low] < a[high]){
            ans = min(ans,a[low]);
            break;
        }
        if(a[low] <= a[mid]){
            ans = min(ans, a[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, a[mid]);
            high = mid - 1;
        }
    }
    return ans;
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
    //int ans = minElement(a,n);
    int ans = minElementDuplicates(a,n);
    cout << ans;
}