#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//brute force
//TC O(n^3 * log(no. of unique triplets)) sorting time neglected as we are sorting only 3 elements at a time
//SC (2 * no. of the unique triplets)
vector<vector<int>> threeSum(vector<int> &num, int n){
    set<vector<int>> st;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                if(num[i]+num[j]+num[k]==0){
                    vector<int> temp = {num[i],num[j],num[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//better
//TC O(n^2 * log(no. of unique triplets)) sorting time neglected as we are sorting only 3 elements at a time
//SC O(2 * no. of the unique triplets) + O(n) for hashMap
vector<vector<int>> threeSumBetter(vector<int> &num, int n){
    set<vector<int>> st;
    for(int i = 0;i<n;i++){
        set<int> hashMap;
        for(int j = i+1;j<n;j++){
            int third = -(num[i]+num[j]);
            if(hashMap.find(third)!=hashMap.end()){
                vector<int> temp = {num[i],num[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashMap.insert(num[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//optimal
//TC O(nlogn)+O(n^2) sort + loops
//SC O(no. of triplets) = O(1) no extra space
vector<vector<int>> threeSumOptimal(vector<int> &num, int n){
    vector<vector<int>> ans;
    sort(num.begin(),num.end());
    for(int i = 0;i<n;i++){
        if(i != 0 && num[i]==num[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = num[i]+num[j]+num[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                vector<int> temp = {num[i],num[j],num[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && num[j] == num[j-1]) j++;
                while(j<k && num[k] == num[k+1]) k--;
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
    //vector<vector<int>> m = threeSum(a,n);
    vector<vector<int>> m = threeSumBetter(a,n);
    //vector<vector<int>> m = threeSumOptimal(a,n);
    for(auto it : m){
        for(auto el : it){
            cout << el <<" ";
        }
        cout << endl;
    }
}