#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev = 1;
        for(int i=2; i<=n; i++){
            int curr = prev+prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main(){
    int n;
    cin >> n;
    Solution s;
    int ans = s.climbStairs(n);
    cout << ans;
}