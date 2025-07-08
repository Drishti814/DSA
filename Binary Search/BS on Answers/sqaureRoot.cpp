#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force
//O(num)
int sqrt(int num){
    int ans = 0;
    for(int i = 0;i<=num;i++){
        if(i*i<=num) ans = i;
        else break;
    }
    return ans;
}

//optimal
//O(log(num))
int sqrtOptimal(int num){
    int ans = 0;
    int low = 0;
    int high = num;
    while(low<=high){
        long long mid = (low+high)/2;
        if(mid*mid<=num){
            ans = mid;
            low = mid +1;
        }
        else if(mid*mid>num){
            high = mid - 1;
        }
    }
    return ans; //high will give the sqrt
    //low will the give next value 
}

int main(){
    int num;
    cin >> num;
    //int ans = sqrt(num);
    int ans = sqrtOptimal(num);
    cout << ans;
}