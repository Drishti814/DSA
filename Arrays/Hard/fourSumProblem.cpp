#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//brute force
//TC O(n^4) sorting time neglected as we are sorting only 4 elements at a time
//SC (2 * no. of the unique triplets)
vector<vector<int>> fourSum(vector<int> &num, int n, int target){
    set<vector<int>> st;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                for(int l = k+1;l<n;l++){
                    long long sum = num[i]+num[j]+num[k]+num[l];
                    if(sum==target){
                    vector<int> temp = {num[i],num[j],num[k],num[l]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    }
                } 
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//better
//TC O(n^3 * log(no. of elements in set)) sorting time neglected as we are sorting only 4 elements at a time
//SC O(2 * no. of the unique triplets) + O(n) for hashMap
vector<vector<int>> fourSumBetter(vector<int> &num, int n, int target){
    set<vector<int>> st;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            set<long long> hashSet;
            for(int k = j+1;k<n;k++){
                long long fourth = target-(num[i]+num[j]+num[k]);
                if(hashSet.find(fourth)!=hashSet.end()){
                    vector<int> temp = {num[i],num[j],num[k],(int)fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                 hashSet.insert(num[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//optimal
//TC O(nlogn)+O(n^3) sort + loops
//SC O(no. of triplets) = O(1) no extra space
vector<vector<int>> fourSumOptimal(vector<int> &num, int n, int target){
    vector<vector<int>> ans;
    sort(num.begin(),num.end());
    for(int i = 0;i<n;i++){
        if(i != 0 && num[i]==num[i-1]) continue;
        for(int j = i+1;j<n;j++){
            if(j != i+1 && num[j]==num[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = num[i]+num[j]+num[k]+num[l];
                if(sum < target) k++;
                else if(sum > target) l--;
                else{
                    vector<int> temp = {num[i],num[j],num[k],num[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && num[k] == num[k-1]) k++;
                    while(k<l && num[l] == num[l+1]) l--;
                }
            }
        }
    }
    return ans;
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
    int t;
    cin >> t;
    //vector<vector<int>> m = fourSum(a,n,t);
    //vector<vector<int>> m = fourSumBetter(a,n,t);
    vector<vector<int>> m = fourSumOptimal(a,n,t);
    for(auto it : m){
        for(auto el : it){
            cout << el <<" ";
        }
        cout << endl;
    }
}