#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//brute force
//O(nlogn)
//sorting

//better
//O(nlogn) TC map
//O(n) TC unordered map, O(n^2) worst case
//O(n) SC
void sortArray(vector<int>& a) {
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        for(int i = 0;i<a.size();i++){
            if(a[i]==0) c1++;
            else if(a[i]==1) c2++;
            else c3++;
        }
        for(int i = 0;i<c1;i++){
            a[i] = 0;
        }
        for(int i = c1;i<c1+c2;i++){
            a[i] = 1;
        }
        for(int i = c1+c2;i<a.size();i++){
            a[i] = 2;
        }
    }

//dutch national flag algorithm
void sortArray012(vector<int>& a, int n){
    int low = 0,mid = 0,high = n-1;
    while(mid <= high){
        if(a[mid]==0){
            swap(a[mid],a[low]);
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    //sortArray(a);
    sortArray012(a,n);
    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
}