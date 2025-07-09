#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
using namespace std;

int findMax(vector<int> &a,int n){
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        maxi = max(a[i],maxi);
    }
    return maxi;
}

//brute force
//TC O(n*max(a))
int smallestDiv(vector<int> &a, int n, int threshold){
    int maxi = findMax(a,n);
    for(int div = 1;div<=maxi;div++){
        int val = 0;
        for(int i = 0;i<n;i++){
            val += ceil((double)a[i]/(double)div);
        }
        if(val<=threshold){
            return div;
        }
    }
    return -1;
}

//optimal
//TC O(n*log(max(a)))
int smallestDivOptimal(vector<int> &a, int n, int threshold){
    int ans = -1;
    if(n > threshold) return ans;
    int maxi = findMax(a,n);
    int low = 1;
    int high = maxi;
    while(low<=high){
        int mid = (low+high)/2;
        int val = 0;
        for(int i = 0;i<n;i++){
            val += ceil((double)a[i]/(double)mid);
        }
        if(val<=threshold){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int threshold;
    cin >> threshold;
    //int div = smallestDiv(a,n,threshold);
    int div = smallestDivOptimal(a,n,threshold);
    cout << div;
}