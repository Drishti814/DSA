#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//brute force
//TC O(n^2)
//SC O(1)
vector<int> missingAndRepeating(vector<int> &arr,int n){
    int missing = -1;
    int repeating = -1;
    for(int i = 1;i<=n;i++){
        int count = 0;
        for(int j = 0;j<n;j++){
            if(arr[j]==i){
                count++;
            }
        }
        if(count==2) repeating = i;
        else if(count==0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
    return {missing, repeating};
}

//better
//TC O(2n)
//SC O(n)
vector<int> missingAndRepeatingBetter(vector<int> &arr,int n){
    int missing = -1;
    int repeating = -1;
    vector<int> hashArr(n+1,0);
    for(int i = 0;i<n;i++){
        hashArr[arr[i]]++;
    }
    for(int i = 1;i<=n;i++){
        if(hashArr[i]==2) repeating = i;
        else if(hashArr[i]==0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
    return {missing, repeating};
}

//optimal using sum
//TC O(n)
//SC O(1)
vector<int> missingAndRepeatingOptimal1(vector<int> &arr,int n){
    long long sum = (n*(n+1))/2;
    long long sumSq = (n*(n+1)*(2*n+1))/6;
    long long s = 0;
    long long sSq = 0;
    for(int i = 0;i<n;i++){
        s += (long long)arr[i];
        sSq += (long long)arr[i]*(long long)arr[i];
    }
    long long val1 = s - sum;
    long long val2 = sSq - sumSq;
    val2 = val2 / val1;
    long long repeating = (val1 + val2) / 2;
    long long missing = repeating - val1;
    return {(int)missing, (int)repeating};
}

//optimal using XOR
//TC O(n) approx
//SC O(1)
vector<int> missingAndRepeatingOptimal2(vector<int> &arr,int n){
    int Xor = 0;
    for(int i = 0;i<n;i++){
        Xor = Xor ^ arr[i];
        Xor = Xor ^ (i+1);
    }
    int bit = 0;
    while(1){
        if((Xor&(1<<bit))!=0){
            break;
        }
        bit++;
    }
    int zero = 0;
    int one = 0;
    for(int i = 0;i<n;i++){
        if((arr[i] & (1<<bit))!=0){
            one = one ^ arr[i];
        }
        else{
            zero = zero ^ arr[i];
        }
    }
    for(int i = 1;i<=n;i++){
        if((i & (1<<bit))!=0){
            one = one ^ i;
        }
        else{
            zero = zero ^ i;
        }
    }
    int missing = one;
    int repeating = zero;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]==zero) cnt++;
    }
    if(cnt==2)  return {repeating,missing};
    else return {missing, repeating};
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    //vector<int> m = missingAndRepeating(arr,n);
    //vector<int> m = missingAndRepeatingBetter(arr,n);
    //vector<int> m = missingAndRepeatingOptimal1(arr,n);
    vector<int> m = missingAndRepeatingOptimal2(arr,n);
    for(auto it : m){
        cout << it << " ";
    }
}