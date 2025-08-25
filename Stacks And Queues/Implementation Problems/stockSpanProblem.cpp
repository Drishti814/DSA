#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

//brute force
//TC O(number of days)
//SC O(total number of next calls)
class StockSpanner {
public:
    vector<int> arr;
    int cnt;
    StockSpanner() {
        arr = {};
    }
    
    int next(int price) {
        arr.push_back(price);
        cnt = 1;
        for(int i = arr.size()-2;i>=0;i--){
            if(arr[i]<=price) cnt++;
            else break;
        }
        return cnt;
    }
};

//optimal
//TC O(2N)
//SC O(N)
class StockSpannerOptimal {
public:
    stack<pair<int,int>> st;
    int ind;
    int ans;
    StockSpannerOptimal() {
        st.empty();
        ind = -1;
        ans = 1;
    }
    
    int next(int price) {
        ind = ind+1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        ans = ind - (st.empty()?-1:st.top().second);    //return ans first or u will lose nge
        st.push({price,ind});
        return ans;
    }
};

int main(){
    //StockSpanner obj;
    StockSpannerOptimal obj;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << "next(" << price << ") -> " << obj.next(price) << endl;
    }
}